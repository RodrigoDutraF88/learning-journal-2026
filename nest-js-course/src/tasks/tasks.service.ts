import { HttpException, HttpStatus, Injectable } from '@nestjs/common';
import { Task} from './entities/task.entity';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
import { PrismaService } from 'src/prisma/prisma.service';


@Injectable()
export class TasksService {

    constructor(private prisma: PrismaService){}

    private tasks:  Task[] = [
        {
            id: 1,
            name: "testando entity",
            description: "aprendendo",
            completed: false,
        }
    ]

    async findAll(){
        const alltasks = await this.prisma.task.findMany();
        return alltasks;
    }

    findOne(id: number){
       const task = this.tasks.find(task => task.id == id)

       if ( task) return task;

       throw new HttpException("essa tarefa nao existe",HttpStatus.NOT_FOUND)  

    }

    create(CreateTaskDto: CreateTaskDto){
        const newId = this.tasks.length + 1;
        const newTask = {
            id: newId,
            ...CreateTaskDto,
            completed: false,
        }
        this.tasks.push(newTask);
        return newTask

    }

    update(id: number, UpdateTaskDto: UpdateTaskDto){
        const taskIndex = this.tasks.findIndex(task => task.id == id)
        if(taskIndex < 0){
            throw new HttpException("essa tarefa nao existe",HttpStatus.NOT_FOUND)
        }
 
            

        const taskItem = this.tasks[taskIndex];

        this.tasks[taskIndex] = { //agora modifica
                ...taskItem,
                ...UpdateTaskDto,
        }

    
        return "tarefa atualizada com sucesso";


    }
    delete(id: number){
        const taskIndex = this.tasks.findIndex(task => task.id == id)

        if(taskIndex < 0){
            throw new HttpException("essa tarefa nao existe",HttpStatus.NOT_FOUND)
        }

        this.tasks.splice(taskIndex, 1)

        return {
            message: "task deletada"
        }



    }


}
