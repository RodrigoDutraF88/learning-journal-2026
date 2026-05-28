import { Injectable } from '@nestjs/common';

@Injectable()
export class TasksService {

    findAll(){
        return[
            {id:1, task: "Comprar pao"}
        ]
    }

    findOne(id: string){
        return "Buscar tarefa com id" + id;
    }
}
