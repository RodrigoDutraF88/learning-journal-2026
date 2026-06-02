import { HttpException, HttpStatus, Injectable,  } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';

@Injectable()
export class UsersService {

    constructor(private prisma: PrismaService){}

     async findOne(id: number){
        const user = await this.prisma.user.findFirst({
            where:{
                id: id,
            },
            select:{
                id:true,
                email: true,
                name: true,
                Task: true
            }
        })

        if(user) return user;
        throw new HttpException('Usuario nao encontrado', HttpStatus.NOT_FOUND);
        
    }

    async createUser(createuserDto: CreateuserDto){

        try{
            const newUser = await this.prisma.user.create({
                data:{
                    name: createuserDto.name,
                    email: createuserDto.email,
                    passwordHash: createuserDto.password
                },
                select:{
                    id: true,
                    name: true,
                    email: true,

                }
            })

            return newUser;


        }catch(err){
            throw new HttpException('Usuario nao encontrado', HttpStatus.NOT_FOUND);
        }
    }   

    async update(id: number, updateUserDto: UpdateUserDto){
        try{
            const user = await this.prisma.user.findFirst({
                where:{
                    id: id,
                },
            })

            if(!user){
                  throw new HttpException('Falha ao atualizar', HttpStatus.NOT_FOUND);

            }

            const updateUser = await this.prisma.user.update({
                where:{
                    id: user.id,

                },
                data:{
                    name: updateUserDto.name ? updateUserDto.name : user.name,
                    passwordHash: updateUserDto.password ? updateUserDto.password : user.passwordHash
                },
                select:{
                    id: true,
                    name: true,
                    email: true,

                }
            })
        }catch(err){
             throw new HttpException('Usuario nao encontrado', HttpStatus.NOT_FOUND);

        }

    
       
        
            
    }

    async delete(id: number){
        try{
            const user = await this.prisma.user.findFirst({
                where:{
                    id: id,
                },
            })

            if(!user){
                  throw new HttpException('Falha ao atualizar', HttpStatus.NOT_FOUND);

            }

            await this.prisma.user.delete({
                where:{
                    id: user.id
                }
            })
            return{
                message: "usuario deletado com sucesso"
            }

        }catch(err){
            throw new HttpException('Falha a deletar user', HttpStatus.NOT_FOUND);

        }
    }




        
 
}




   