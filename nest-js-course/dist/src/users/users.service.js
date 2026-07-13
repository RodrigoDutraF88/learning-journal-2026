"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.UsersService = void 0;
const common_1 = require("@nestjs/common");
const prisma_service_1 = require("../prisma/prisma.service");
const hashing_service_1 = require("../auth/hash/hashing.service");
const path_1 = __importDefault(require("path"));
const promises_1 = __importDefault(require("fs/promises"));
let UsersService = class UsersService {
    prisma;
    hashingservice;
    constructor(prisma, hashingservice) {
        this.prisma = prisma;
        this.hashingservice = hashingservice;
    }
    async findOne(id) {
        const user = await this.prisma.user.findFirst({
            where: {
                id: id,
            },
            select: {
                id: true,
                email: true,
                name: true,
                Task: true
            }
        });
        if (user)
            return user;
        throw new common_1.HttpException('Usuario nao encontrado', common_1.HttpStatus.NOT_FOUND);
    }
    async createUser(createuserDto) {
        try {
            const passwordHash = await this.hashingservice.hash(createuserDto.password);
            const newUser = await this.prisma.user.create({
                data: {
                    name: createuserDto.name,
                    email: createuserDto.email,
                    passwordHash: passwordHash
                },
                select: {
                    id: true,
                    name: true,
                    email: true,
                }
            });
            return newUser;
        }
        catch (err) {
            throw new common_1.HttpException('Usuario nao encontrado', common_1.HttpStatus.NOT_FOUND);
        }
    }
    async update(id, updateUserDto, tokenPayload) {
        try {
            const user = await this.prisma.user.findFirst({
                where: {
                    id: id,
                },
            });
            if (!user) {
                throw new common_1.HttpException('Falha ao atualizar', common_1.HttpStatus.NOT_FOUND);
            }
            if (user.id !== tokenPayload.sub) {
                throw new common_1.HttpException('Acesso negado', common_1.HttpStatus.BAD_REQUEST);
            }
            const dataUser = {
                name: updateUserDto.name ? updateUserDto.name : user.name,
            };
            if (updateUserDto?.password) {
                const passwordHash = await this.hashingservice.hash(updateUserDto.password);
                dataUser['passwordHash'] = passwordHash;
            }
            const updateUser = await this.prisma.user.update({
                where: {
                    id: user.id,
                },
                data: {
                    name: dataUser.name,
                    passwordHash: dataUser?.passwordHash ? dataUser?.passwordHash : user.passwordHash
                },
                select: {
                    id: true,
                    name: true,
                    email: true,
                }
            });
        }
        catch (err) {
            throw new common_1.HttpException('Falha ao atualizar usuario', common_1.HttpStatus.NOT_FOUND);
        }
    }
    async delete(id, tokenPayload) {
        try {
            const user = await this.prisma.user.findFirst({
                where: {
                    id: id,
                },
            });
            if (!user) {
                throw new common_1.HttpException('Falha ao atualizar', common_1.HttpStatus.NOT_FOUND);
            }
            if (user.id !== tokenPayload.sub) {
                throw new common_1.HttpException('acesso negado', common_1.HttpStatus.BAD_REQUEST);
            }
            await this.prisma.user.delete({
                where: {
                    id: user.id
                }
            });
            return {
                message: "usuario deletado com sucesso"
            };
        }
        catch (err) {
            throw new common_1.HttpException('Falha a deletar user', common_1.HttpStatus.NOT_FOUND);
        }
    }
    async uploadAvatarImage(tokenPayload, file) {
        try {
            const mimeType = file.mimetype;
            const fileExtension = path_1.default.extname(file.originalname).toLowerCase().substring(1);
            const fileName = `${tokenPayload.sub}.${fileExtension}`;
            const fileLocale = path_1.default.resolve(process.cwd(), 'files', fileName);
            await promises_1.default.writeFile(fileLocale, file.buffer);
            const user = await this.prisma.user.findFirst({
                where: {
                    id: tokenPayload.sub
                }
            });
            if (!user) {
                throw new common_1.HttpException('Falha ao atualizar o avatar do usuário!', common_1.HttpStatus.BAD_REQUEST);
            }
            const updatedUser = await this.prisma.user.update({
                where: {
                    id: user.id
                },
                data: {
                    avatar: fileName
                },
                select: {
                    id: true,
                    email: true,
                    avatar: true,
                    name: true
                }
            });
            return updatedUser;
        }
        catch (err) {
            console.log(err);
            throw new common_1.HttpException('Falha ao atualizar o avatar do usuário!', common_1.HttpStatus.BAD_REQUEST);
        }
    }
};
exports.UsersService = UsersService;
exports.UsersService = UsersService = __decorate([
    (0, common_1.Injectable)(),
    __metadata("design:paramtypes", [prisma_service_1.PrismaService,
        hashing_service_1.HashingServiceProtocol])
], UsersService);
//# sourceMappingURL=users.service.js.map