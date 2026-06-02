import { PartialType } from "@nestjs/mapped-types";
import { CreateuserDto } from "./create.user.dto";

export class UpdateUserDto extends PartialType(CreateuserDto){}