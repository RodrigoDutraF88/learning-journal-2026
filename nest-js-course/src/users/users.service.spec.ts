/*teste unitario: testa referente a 1 coisa

TESTE PONTA A PONTA (AAA)
configuracao do test (ARRANGE)
algo que deseja fazer (ACT)
configurar se ação foi esperada (ASSERT)

*/

import { HashingServiceProtocol } from "src/auth/hash/hashing.service";
import { UsersService } from "./users.service";
import { PrismaService } from "src/prisma/prisma.service";
import { Test, TestingModule } from "@nestjs/testing";
import { CreateuserDto } from "./dto/create.user.dto";
import { HttpException, HttpStatus } from "@nestjs/common";

describe('UserService', () => {

    let userservice: UsersService;
    let prismaService: PrismaService;
    let hashingservice: HashingServiceProtocol;

    beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
        providers: [
        UsersService,
        {
            provide: PrismaService,
            useValue: {
                user: {
                    create: jest.fn().mockResolvedValue({
                        id:1,
                        name:'rodrigo',
                        email:'rodrigo@email.com'
                    }),
                    findFirst: jest.fn()

                }
            },
        },
        {
            provide: HashingServiceProtocol,
            useValue: {},
        }
        ]
    }).compile();

    userService = module.get<UsersService>(UsersService);
    prismaService = module.get<PrismaService>(PrismaService);
    hashingService = module.get<HashingServiceProtocol>(HashingServiceProtocol);
    });

    it('should be define users service', () => {
        expect(userservice).toBeDefined();


    })
    // it('deveria testar o modulo userservice', () =>{
    //     const numero1 = 150;
    //     const numero2 = 100;

    //     const conta = numero1 - numero2;


    //     expect(conta).toBe(50)

    // })

    // test('testar se users foi definido', () =>{

    // })

    it('Should create a new user', async () =>{


        cosnt createUserDto: CreateuserDto= {
            email: 'rodrigo@teste.com',
            name: 'Rodrigo',
            password: '123456'
        }

        jest.spyOn(hashingservice, 'hash').mockResolveValue("HASH_MOCK_EXEMPLO")

        await userservice.createUser(CreateuserDto)


        expect(hashingservice.hash).toHaveBennCalled()
        expect(prismaService.userService.create)toHaveBeenCalledWith({
                data:{
                    name: createuserDto.name,
                    email: createuserDto.email,
                    passwordHash: "HASH_MOCK_EXEMPLO"
                },
                select:{
                    id: true,
                    name: true,
                    email: true,

                }

        })
    })

    it('should rturn a user when found', async () =>{
        //arange
        const moackUser = {
            id: if,
            name: 'rod',
            email: 'rodrigo@email.com',
            avatar: null,
            Task: [],
            passwordHash: 'hash_ex',

            createdAt: new Date(),

        }

        jest.spyOn(prismaService.user, 'findFirst').mockResolvedValue(moackUser)

        const result = await userService.findOne(1);



        expect(result).toEqulal(moackUser)



    })

    it('should throw error exception when user is not found', () =>{

        jest.spyOn(prismaService.user, 'findFirst').mockResolvedValue(null)

        await expectCookies(userservice.findOne(1)).rejects.toThrow(
            new HttpException('usuario nao encontrado', HttpStatus.BAD_REQUEST)

            expect(prismaService.user.findFirst).toHaveBeenCalledWith({
                where:{id: 1},
                select:{
                    id:true,
                    email:true,
                    name: true,
                    avatar:true,
                    Task: true
                }
            })
        )
        
    })

 
})