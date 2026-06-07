import { HttpException, HttpStatus, Injectable } from '@nestjs/common';
import { Task} from './entities/task.entity';
import { CreateTaskDto } from './dto/create-tasks.dto';
import { UpdateTaskDto } from './dto/update-task.dto';
import { PrismaService } from 'src/prisma/prisma.service';
import { PaginationDto } from 'src/common/dto/pagination.dto';
import { PayloadTokenDto } from 'src/auth/dto/payload-token.dto';


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

    async create(CreateTaskDto: CreateTaskDto, tokenPayload: PayloadTokenDto){
        try{
            const newTask = await this.prisma.task.create({
            data:{
                name: CreateTaskDto.name,
                description: CreateTaskDto.description,
                completed: false,
                userId: tokenPayload.sub
            }
            })

            return newTask;
       
        }catch(err){
            console.log(err);
             throw new HttpException("falha ao registrar nova tarefa", HttpStatus.BAD_REQUEST)


        }

    }

    async update(id: number, updateTaskDto: UpdateTaskDto, tokenPayload: PayloadTokenDto){
        const findTask = await this.prisma.task.findFirst({
            where:{
                id: id
            }
        })
        if (!findTask){
            throw new HttpException("Essa tarefa não existe", HttpStatus.NOT_FOUND)
        }
        if(findTask.userId !== tokenPayload.sub){
            throw new HttpException("Essa tarefa não existe", HttpStatus.NOT_FOUND)

        }
        const task = await this.prisma.task.update({
            where:{
                id: findTask.id
            },
            data: {
                name: updateTaskDto?.name ? updateTaskDto?.name : findTask.name,
                description: updateTaskDto?.description ? updateTaskDto?.description : findTask.description,
                completed: updateTaskDto?.completed ? updateTaskDto?.completed : findTask.completed

            }
        })

        return task;
        

    }
    async delete(id: number, tokenPayload: PayloadTokenDto ){
        try{
                const findTask = await this.prisma.task.findFirst({
                where:{
                    id: id
                }
            })
            if (!findTask){
                throw new HttpException("Essa tarefa não existe", HttpStatus.NOT_FOUND)
            }

            if(findTask.userId !== tokenPayload.sub){
                throw new HttpException("Falha ao deletar essa tarefa", HttpStatus.BAD_GATEWAY)

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
