import { PartialType } from "@nestjs/swagger";
import { CreateuserDto } from "./create.user.dto";

export class UpdateUserDto extends PartialType(CreateuserDto){}