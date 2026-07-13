import { IsBoolean, IsNotEmpty, IsOptional, IsString } from "class-validator";
import { PartialType } from "@nestjs/swagger";
import { CreateTaskDto} from '../dto/create-tasks.dto';
// export class UpdateTaskDto{
//     @IsString()
//     @IsOptional()
//     readonly name?: string;

//     @IsString()
//     @IsOptional() 
//     readonly description?: string;



// }
export class UpdateTaskDto extends PartialType(CreateTaskDto){

    @IsBoolean()
    @IsOptional()
    readonly completed?: boolean;


}