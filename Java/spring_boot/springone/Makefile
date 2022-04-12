run: package
	make launch
package:
	./mvnw package
launch:
	java -jar target/springone-0.0.1-SNAPSHOT.jar

docker-build:
	docker build -t springone .

docker-run:
	docker run -p 8080:8080 springone

depen-file:
	mkdir -p target/dependency && (cd target/dependency; jar -xf ../*.jar)

spring-build-image:
	./mvnw spring-boot:build-image -Dspring-boot.build-image.imageName=springio/springone-docker-image