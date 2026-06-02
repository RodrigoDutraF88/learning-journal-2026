import { HttpException, HttpStatus, Injectable } from '@nestjs/common';
import { Task} from './entities/task.entity';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
import { PrismaService } from 'src/prisma/prisma.service';
import { PaginationDto } from 'src/common/dto/pagination.dto';


@Injectable()
export class TasksService {

    constructor(private prisma: PrismaService){}



    async findAll(paginationDto?: PaginationDto){
        const { limit = 10, offset = 0} = paginationDto || {};

        const alltasks = await this.prisma.task.findMany({
            take: limit,
            skip: offset
        });
        return alltasks;
    }

    findOne(id: number){
       const task = this.prisma.task.findFirst({
        where:{
            id: id
        }
       })

       if ( task) return task;

       throw new HttpException("essa tarefa nao existe",HttpStatus.NOT_FOUND)  

    }

    async create(CreateTaskDto: CreateTaskDto){
        const newTask = await this.prisma.task.create({
            data:{
                name: CreateTaskDto.name,
                description: CreateTaskDto.description,
                completed: false,
            }
        })

        return newTask;
       
    }

    async update(id: number, UpdateTaskDto: UpdateTaskDto){
        const findTask = await this.prisma.task.findFirst({
            where:{
                id: id
            }
        })
        if (!findTask){
            throw new HttpException("Essa tarefa não existe", HttpStatus.NOT_FOUND)
        }
        const task = await this.prisma.task.update({
            where:{
                id: findTask.id
            },
            data: UpdateTaskDto
        })

        return task;
        

    }
    async delete(id: number){
        try{
                const findTask = await this.prisma.task.findFirst({
                where:{
                    id: id
                }
            })
            if (!findTask){
                throw new HttpException("Essa tarefa não existe", HttpStatus.NOT_FOUND)
            }

            await this.prisma.task.delete({
                where:{
                    id: findTask.id

                }

            })
            return {
                message:"Tarefa deletada com sucesso"
            }
        }catch(err){
            throw new HttpException("Falha ao deletar tarefa", HttpStatus.BAD_REQUEST)

        }
    }


        

}
