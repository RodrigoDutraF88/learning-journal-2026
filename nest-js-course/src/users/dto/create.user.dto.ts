import { IsEmail, IsNotEmpty, IsString, MinLength } from "class-validator";

export class CreateuserDto{

    @IsString()
    @IsNotEmpty()
    name!: string;

    @IsEmail()
    email!: string;

    @IsString()
    @MinLength(6)
    @IsNotEmpty()
    password!: string;
   
}