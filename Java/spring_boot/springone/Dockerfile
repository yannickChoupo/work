FROM openjdk:17-jdk-alpine
ARG JAR_FILE=target/*.jar
RUN addgroup -S spring && adduser -S spring -G spring
USER spring:spring

ARG DEPENDENCY=target/dependency
COPY ${DEPENDENCY}/BOOT-INF/lib /app/lib
COPY ${DEPENDENCY}/META-INF /app/META-INF
COPY ${DEPENDENCY}/BOOT-INF/classes /app

# ENTRYPOINT ["java","-jar","/app.jar"]

ENTRYPOINT ["java","-cp","app:app/lib/*","com.apps.springone.SpringoneApplication"]