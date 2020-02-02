from django.shortcuts import render

# Create your views here.
from rest_framework import viewsets
from cluster.models import Cluster
from cluster.serializers import ClusterSerializer
from rest_framework.parsers import JSONParser

from pprint import pprint
from django.shortcuts import get_object_or_404
from kubernetes.client import Configuration, ApiClient, CoreV1Api
from rest_framework import viewsets
from rest_framework.decorators import action

def get_config(cluster):
    '''
    :param cluster:  k8s集群的配置对象
    :return:   返回一个config对象
    '''
    configuration = Configuration()
    configuration.verify_ssl = False
    configuration.host = cluster.api
    configuration.api_key['authorization'] = cluster.token
    configuration.api_key_prefix['authorization'] = 'Bearer'
    return configuration

def get_clients(cluster):
    '''
    :param cluster: k8s集群对象
    :return:  一个apiclient对象，一个coreV1Api对象
    '''
    api_client = ApiClient( get_config( cluster ) )
    return api_client, CoreV1Api( api_client )

class ClusterViewSet( viewsets.ModelViewSet ):
    queryset         = Cluster.objects.all()
    serializer_class = ClusterSerializer
    parser_classes   = (JSONParser,) 


    # /api/cluster/[pk]/list_service/
    @action( detail=True, methods=['get'] )
    def list_service(self, request, pk=None):
        cluster = get_object_or_404( Cluster, pk=pk )
        api_client, core_v1_api = get_clients( cluster )
        v1_service_list = core_v1_api.list_service_for_all_namespaces()
        # pprint(v1_service_list)
        result = {}
        items = []
        headers = ['NAMESPACE', 'NAME', 'TYPE', 'CLUSTER-IP', 'SELF LINK']

        for item in v1_service_list.items:
            items.append( [item.metadata.namespace,
                           item.metadata.name,
                           item.spec.cluster_ip, item.spec.type, item.metadata.self_link
                           ] )

        result['items'] = items
        result['headers'] = headers
        result['caption'] = "Services"
        return render( request, "table.html", {'result': result} )

    # /api/cluster/[pk]/list_pod/
    @action( detail=True, methods=['get'] )
    def list_pod(self, request, pk=None):
        cluster = get_object_or_404( Cluster, pk=pk )
        api_client, core_v1_api = get_clients( cluster )
        v1_service_list = core_v1_api.list_pod_for_all_namespaces()
        # pprint(v1_service_list)
        result = {}
        items = []
        headers = ['NAMESPACE', 'NAME', 'IP', 'NODE']

        for item in v1_service_list.items:
            items.append( [
                item.metadata.namespace,
                item.metadata.name,
                item.status.host_ip,
                item.status.pod_ip,
            ] )

        result['items'] = items
        result['headers'] = headers
        result['caption'] = "Pods"
        return render( request, "templates/table.html", {'result': result} )
