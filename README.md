Go to the project directory

```bash
  cd my-project
```

From Vscode Extension
 ```bash
 1.Install Docker
 2.Install Dev-container
 3.sudo groupadd docker
 4.sudo usermod -aG docker $USER
 ```

Start the Docker

```bash
  sudo systemctl start docker
```

Build Docker Image 

```bash
   sudo docker build -t dsa-dev
```

Start the Docker Image

```bash
  sudo docker run -it --rn -v `pwd`:/work dsa-dev
```

List the Docker Image

```bash
  sudo docker container ls
```

Stop the Docker Image

```bash
  sudo docker stop  container_ID
```

Finally open File in Remote server Vscode

From Remote Vscode Extension
 ```bash
 1.Install C++ extensions
 2.Install Cmake extension
 ```