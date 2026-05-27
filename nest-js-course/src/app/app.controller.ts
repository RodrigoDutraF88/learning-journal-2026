import { Controller, Get } from '@nestjs/common';
import { AppService } from './app.service';

@Controller() //recebe endpoint 
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get() //rota 
  getHello(): string { 
    return this.appService.getHello(); //passa servico
  }
  @Get("/test") //rota de teste ,decorator
  getTest(){
    return "rota de teste api"
  } 
}
