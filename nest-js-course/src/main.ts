import { NestFactory } from '@nestjs/core';
import { AppModule } from './app/app.module'; //importa modulo

// app module : modulo principak do aplicativo
// controller : define as rotas e lida com requisicoes
// service: contem a logica de negocio separado do controlador
async function bootstrap() {
  const app = await NestFactory.create(AppModule); // cria o modulo principal
  await app.listen(process.env.PORT ?? 3000); //ouve na porta 3000
}
bootstrap(); //funcao para inicializar o projeto

//arquivo que nicializar o projeto