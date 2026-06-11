import { NestFactory } from '@nestjs/core';
import { AppModule } from './app/app.module'; //importa modulo
import { ValidationPipe } from '@nestjs/common';
import { DocumentBuilder, SwaggerModule } from '@nestjs/swagger';

// app module : modulo principak do aplicativo
// controller : define as rotas e lida com requisicoes
// service: contem a logica de negocio separado do controlador
async function bootstrap() {
  const app = await NestFactory.create(AppModule);// cria o modulo principal

  app.enableCors({
    origin: '*'
  }) //libera tds usarem
  app.useGlobalPipes(new ValidationPipe({
    whitelist: true, // se TRUE ele remove as chaves que nao estao no DTO
  })) 


  const configSwagger = new DocumentBuilder()
  .setTitle('Lista de tarefas')
  .setDescription('API lista de tarefas')
  .addBearerAuth()
  .setVersion('1.0')
  .build();

  const documentFactory = () => SwaggerModule.createDocument(app, configSwagger)
  SwaggerModule.setup('docs', app, documentFactory)






  await app.listen(process.env.PORT ?? 3000); //ouve na porta 3000
}
bootstrap(); //funcao para inicializar o projeto

//arquivo que nicializar o projeto