import { Injectable } from '@nestjs/common';

@Injectable() //logica 
export class AppService {
  getHello(): string {
    return 'meu segundo projeto com nest';
  }
}
