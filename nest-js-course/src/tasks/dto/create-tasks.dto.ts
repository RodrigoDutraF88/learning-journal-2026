//dto é um DATA TRANSFER OBJECT ( objeto de transferencia de dados )//

import { IsNotEmpty, IsString, MinLength } from "class-validator";

//validar dados, transformar dados
// se usa para representar quais dados e em que formatos determinada camada aceita e trabalha

export class CreateTaskDto{ 
    @IsString()
    @MinLength(5)
    @IsNotEmpty()
    readonly name!: string;
    
    @IsString()
    @MinLength(5)
    @IsNotEmpty()
    readonly description!: string;




}
