import { Controller, Get, ParseIntPipe, Param, Post, Body, Patch, Delete, UseGuards, Req, UseInterceptors, UploadedFile, UploadedFiles, ParseFilePipeBuilder, HttpStatus } from '@nestjs/common';
import { UsersService } from './users.service';
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { AuthTokenGuard } from 'src/auth/guard/auth.token.guard';
import { TokenPayloadParam } from 'src/auth/param/token-payload.param';
import { PayloadTokenDto } from 'src/auth/dto/payload-token.dto';
import { FileInterceptor, FilesInterceptor } from '@nestjs/platform-express';
import * as path from 'node:path';
import * as fs from 'node:fs/promises';
import { randomUUID } from 'node:crypto';




// Buscar detalhes de 1 usuario
//deltar usuario
// cadastrar usuario
//atualizar usuario especifico
@Controller('users')
export class UsersController {
    constructor(private readonly userService: UsersService) { }


    @Get(':id')
    findOneUser(@Param('id', ParseIntPipe) id: number) {
        console.log('token teste:', process.env.TOKEN_KEY)

        return this.userService.findOne(id);
    }

    @Post()
    createUser(@Body() createUserDto: CreateuserDto) {

        return this.userService.createUser(createUserDto);




    }

    @UseGuards(AuthTokenGuard)
    @Patch(':id')
    updateUser(@Param('id', ParseIntPipe)
    id: number, @Body() updateUserDto: UpdateUserDto,
        @TokenPayloadParam() tokenPayload: PayloadTokenDto) {

        return this.userService.update(id, updateUserDto, tokenPayload);
    }

    @UseGuards(AuthTokenGuard)
    @Delete(':id')
    deleteUser(@Param('id', ParseIntPipe) id: number,
        @TokenPayloadParam() tokenPayload: PayloadTokenDto) {
        return this.userService.delete(id, tokenPayload);
    }

    //@UseGuards(AuthTokenGuard)
    @UseInterceptors(FileInterceptor('file'))
    @Post('upload')
    async upLoadAvatar(
        @TokenPayloadParam() tokenPayload: PayloadTokenDto,
        @UploadedFile(
              new ParseFilePipeBuilder()
                    .addFileTypeValidator({
                    fileType: /jpeg|jpg|png/g,
                    })
                    .addMaxSizeValidator({
                    maxSize: 3 * (1024 * 1024)
                    })
                    .build({
                    errorHttpStatusCode: HttpStatus.UNPROCESSABLE_ENTITY
                    }),
        ) file: any[]
    ) {

        
        return this.userService.uploadAvatarImage(tokenPayload, file)
  
   

    }
}
