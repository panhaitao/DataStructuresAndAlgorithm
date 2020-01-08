# k8s集群管理 MacOS dev
a simple multi k8s cluster web console

# install depends

* pip3 install django
* pip3 install django-restframework 

# start app
django-admin startproject k8s_web_console
cd k8s_web_console
manager.py startapp cluster # 执行前，修改manager.py 首行为如下` #!/usr/bin/env python3`
