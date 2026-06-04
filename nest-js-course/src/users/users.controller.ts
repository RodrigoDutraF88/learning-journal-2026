import { Controller, Get, ParseIntPipe, Param, Post, Body, Patch, Delete } from '@nestjs/common';
import { UsersService } from './users.service';
import { CreateuserDto } from './dto/create.user.dto';
import { UpdateUserDto } from './dto/update-user.dto';


// Buscar detalhes de 1 usuario
//deltar usuario
// cadastrar usuario
//atualizar usuario especifico
@Controller('users')
export class UsersController {
    constructor(private readonly userService: UsersService){}


    @Get(':id')
    findOneUser(@Param('id', ParseIntPipe ) id: number){
        console.log('token teste:', process.env.TOKEN_KEY)

        return this.userService.findOne(id);
    }

    @Post()
    createUser(@Body() createUserDto: CreateuserDto){
        
        return this.userService.createUser(createUserDto);

      
        

    }

    @Patch(':id')
    updateUser(@Param('id', ParseIntPipe) id: number, @Body() updateUserDto: UpdateUserDto){
       return this.userService.update(id, updateUserDto);
    }

    @Delete(':id')
    deleteUser(@Param('id', ParseIntPipe) id: number){
        return this.userService.delete(id);
    }

    
}
