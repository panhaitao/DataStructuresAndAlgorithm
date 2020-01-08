# k8s集群管理 MacOS dev
a simple multi k8s cluster web console

# 第一节: 准备环境

## 安装依赖包

```
mkdir ~/.pip
cat > ~/.pip/pip.conf <<EOF
[global]
index-url = https://mirrors.aliyun.com/pypi/simple
EOF

pip3 install django
pip3 install djangorestframework 
```

## 初始化项目

django-admin startproject k8s_web_console
cd k8s_web_console
manager.py startapp cluster # 执行前，修改manager.py 首行为如下` #!/usr/bin/env python3`

## 在项目配置中加入rest框架

编辑 k8s_web_console/setting.py 修改 INSTALLED_APPS 加入

```
'rest_framework',
  'cluster',
```
## 创建数据库以及数据表

```
python3 manage.py makemigrations
python3 manage.py migrate
```

# 第二节: 开始正真的编码

1. cluster/models.py           cluster应用添加一个k8s集群信息的model
2. cluster/serializers.py      cluster应用添加一个serializers.py文件
3. cluster/views.py            cluster的view文件添加cluster的viewset 
4. k8s_web_console/settings.py 设置rest框架的parser:jsonparser
5. cluster/admin.py            将cluster注册到Django Admin后台
6. k8s_web_console/urls.py                                         设置路由
7. python3 manage.py createsuperuser                               设置用户
8. python3 manage.py makemigrations && python3 manage.py migrate   建数据库以及数据表
9. python3 manage.py runserver 0.0.0.0:8000                        运行服务器
10. 测试
  * http://127.0.0.1:8000/admin/cluster/cluster/ 
  * http://127.0.0.1:8000/api/cluster/

# 第三节: 

