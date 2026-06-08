import { HttpException, HttpStatus, Injectable,  } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { HashingServiceProtocol } from 'src/auth/hash/hashing.service';
import { PayloadTokenDto } from 'src/auth/dto/payload-token.dto';
import path from 'path';
import fs from 'fs/promises';
    
@Injectable()
export class UsersService {

    constructor(
        private prisma: PrismaService,
        private readonly hashingservice: HashingServiceProtocol
    
    ){}

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

            const passwordHash = await this.hashingservice.hash(createuserDto.password);
            const newUser = await this.prisma.user.create({
                data:{
                    name: createuserDto.name,
                    email: createuserDto.email,
                    passwordHash: passwordHash
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

    async update(id: number, updateUserDto: UpdateUserDto, tokenPayload: PayloadTokenDto ){
        try{
            const user = await this.prisma.user.findFirst({
                where:{
                    id: id,
                },
            })

            if(!user){
                  throw new HttpException('Falha ao atualizar', HttpStatus.NOT_FOUND);

            }

            if(user.id !== tokenPayload.sub){
                  throw new HttpException('Acesso negado', HttpStatus.BAD_REQUEST);


            }

            const dataUser: {name?: string, passwordHash?: string} = {
                name: updateUserDto.name ? updateUserDto.name : user.name,
            }
            if(updateUserDto?.password){
                const passwordHash = await this.hashingservice.hash(updateUserDto.password)
                dataUser['passwordHash'] = passwordHash
            }

            const updateUser = await this.prisma.user.update({
                where:{
                    id: user.id,

                },
                data:{
                    name: dataUser.name,
                    passwordHash: dataUser?.passwordHash ? dataUser?.passwordHash : user.passwordHash
                },
                select:{
                    id: true,
                    name: true,
                    email: true,

                }
            })
        }catch(err){
             throw new HttpException('Falha ao atualizar usuario', HttpStatus.NOT_FOUND);

        }

    
       
        
            
    }

    async delete(id: number, tokenPayload: PayloadTokenDto){
        try{
            const user = await this.prisma.user.findFirst({
                where:{
                    id: id,
                },
            })

            if(!user){
                  throw new HttpException('Falha ao atualizar', HttpStatus.NOT_FOUND);

            }

            if(user.id !== tokenPayload.sub){
                  throw new HttpException('acesso negado', HttpStatus.BAD_REQUEST);


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

    async uploadAvatarImage(tokenPayload: PayloadTokenDto, file: any) {
    try {
        const mimeType = file.mimetype;
        const fileExtension = path.extname(file.originalname).toLowerCase().substring(1);

        const fileName = `${tokenPayload.sub}.${fileExtension}`;

        const fileLocale = path.resolve(process.cwd(), 'files', fileName);

        await fs.writeFile(fileLocale, file.buffer);

        const user = await this.prisma.user.findFirst({
        where: {
            id: tokenPayload.sub
        }
        });

        if (!user) {
        throw new HttpException('Falha ao atualizar o avatar do usuário!', HttpStatus.BAD_REQUEST);
        }

        const updatedUser = await this.prisma.user.update({
        where: {
            id: user.id
        },
        data: {
            avatar: fileName // Ajuste este campo conforme o nome da coluna no seu banco
        },
        select:{
            id: true,
            email:true,
            avatar: true,
            name: true
        }
        });

        return updatedUser;
    } catch (err) {
        console.log(err);
        throw new HttpException('Falha ao atualizar o avatar do usuário!', HttpStatus.BAD_REQUEST);
    }
    }



        
 
}




   