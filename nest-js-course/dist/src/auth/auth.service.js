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
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AuthService = void 0;
const common_1 = require("@nestjs/common");
const prisma_service_1 = require("../prisma/prisma.service");
const hashing_service_1 = require("./hash/hashing.service");
const jwt_config_1 = __importDefault(require("./config/jwt.config"));
const jwt_1 = require("@nestjs/jwt");
let AuthService = class AuthService {
    prisma;
    hashingService;
    jwtConfiguration;
    jwtService;
    constructor(prisma, hashingService, jwtConfiguration, jwtService) {
        this.prisma = prisma;
        this.hashingService = hashingService;
        this.jwtConfiguration = jwtConfiguration;
        this.jwtService = jwtService;
    }
    async authenticate(sigInDto) {
        const user = await this.prisma.user.findFirst({
            where: {
                email: sigInDto.email,
                active: true
            }
        });
        if (!user) {
            throw new common_1.HttpException("Falha ao authenticar o usuario", common_1.HttpStatus.UNAUTHORIZED);
        }
        const passwordIsValid = await this.hashingService.compare(sigInDto.password, user.passwordHash);
        if (!passwordIsValid) {
            throw new common_1.HttpException("Senha/usuario incorretos", common_1.HttpStatus.UNAUTHORIZED);
        }
        const token = await this.jwtService.signAsync({
            sub: user.id,
            email: user.email
        }, {
            secret: this.jwtConfiguration.secret,
            expiresIn: this.jwtConfiguration.jwtTtl,
            audience: this.jwtConfiguration.audience,
            issuer: this.jwtConfiguration.issuer
        });
        return {
            id: user.id,
            name: user.name,
            email: user.email,
            token: token
        };
    }
};
exports.AuthService = AuthService;
exports.AuthService = AuthService = __decorate([
    (0, common_1.Injectable)(),
    __param(2, (0, common_1.Inject)(jwt_config_1.default.KEY)),
    __metadata("design:paramtypes", [prisma_service_1.PrismaService,
        hashing_service_1.HashingServiceProtocol, void 0, jwt_1.JwtService])
], AuthService);
//# sourceMappingURL=auth.service.js.map