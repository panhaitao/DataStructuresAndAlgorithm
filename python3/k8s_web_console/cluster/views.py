from django.shortcuts import render

# Create your views here.
from rest_framework import viewsets
from cluster.models import Cluster
from cluster.serializers import ClusterSerializer
from rest_framework.parsers import JSONParser


class ClusterViewSet( viewsets.ModelViewSet ):
    queryset         = Cluster.objects.all()
    serializer_class = ClusterSerializer
    parser_classes   = (JSONParser,) 