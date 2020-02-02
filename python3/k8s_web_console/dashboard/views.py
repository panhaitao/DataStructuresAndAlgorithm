from django.shortcuts import render
from cluster.models import Cluster

def cluster_main(request):
    result = {}
    result['clusters'] = Cluster.objects.all()
    return render(request,'templates/main.html',{'result':result})
