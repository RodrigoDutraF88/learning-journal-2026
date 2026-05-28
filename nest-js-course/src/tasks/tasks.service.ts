import { HttpException, HttpStatus, Injectable } from '@nestjs/common';
import { Task} from './entities/task.entity';


@Injectable()
export class TasksService {

    private tasks:  Task[] = [
        {
            id: 1,
            name: "testando entity",
            description: "aprendendo",
            completed: false,
        }
    ]

    findAll(){
        return this.tasks;
    
    }

    findOne(id: string){
       const task = this.tasks.find(task => task.id == Number(id))

       if ( task) return task;

       throw new HttpException("essa tarefa nao existe",HttpStatus.NOT_FOUND)  

    }

    create(body: any){
        const newId = this.tasks.length + 1;
        const newTask = {
            id: newId,
            ...body,
        }
        this.tasks.push(newTask);
        return newTask

    }

    update(id: string, body: any){
        const taskIndex = this.tasks.findIndex(task => task.id == Number(id))
        if(taskIndex < 0){
            throw new HttpException("essa tarefa nao existe",HttpStatus.NOT_FOUND)
        }
 
            

        const taskItem = this.tasks[taskIndex];

        this.tasks[taskIndex] = { //agora modifica
                ...taskItem,
                ...body,
        }

    
        return "tarefa atualizada com sucesso";


    }
    delete(id: string){
        const taskIndex = this.tasks.findIndex(task => task.id == Number(id))

        if(taskIndex < 0){
            throw new HttpException("essa tarefa nao existe",HttpStatus.NOT_FOUND)
        }

        this.tasks.splice(taskIndex, 1)

        return {
            message: "task deletada"
        }



    }


}
