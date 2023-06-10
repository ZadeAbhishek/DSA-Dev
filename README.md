Go to the project directory

```bash
  cd DSA-Dev
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

Build Docker Image Linux

```bash
   sudo docker build -t <ImageName>
```

Start the Docker Image

```bash
  sudo docker run -it --rm -v `pwd`:/work <ImageName/Id>
```

List the Docker Image

```bash
  sudo docker container ls
```

Stop the Docker Image

```bash
  sudo docker stop  container_ID
```


Build Docker Image Windows

```bash
   docker build ./
```

Start the Docker Image

```bash
   docker run -it --rm -v ${pwd}:/work <ImageId>
```



Finally open File in Remote server Vscode

From Remote Vscode Extension
 ```bash
 1.Install C++ extensions
 2.Install Cmake extension
 ```


 Caution : Always keep update your Date and Time for both OS
