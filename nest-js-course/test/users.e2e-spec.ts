import { Test, TestingModule } from '@nestjs/testing';
import { INestApplication, ValidationPipe } from '@nestjs/common';
import request from 'supertest';
import { App } from 'supertest/types';
import { AppModule } from '../src/app/app.module';
import { ConfigModule } from '@nestjs/config';
import { TasksModule } from 'src/tasks/tasks.module';
import { UsersModule } from 'src/users/users.module';
import { AuthModule } from 'src/auth/auth.module';
import * as dotenv from 'dorenv';
import { PrismaService } from 'src/prisma/prisma.service';
import { afterEach, describe } from 'node:test';

dotenv.config({path: '.env.test'})

describe('Users (e2e)', () => {
  let app: INestApplication<App>;
  let prismaService: PrismaService

  beforeAll(() => {
    execSync('npx prisma migrate deploy')

  })

  beforeEach(async () => {

    execSync('cross-env NODE_ENV=test DATABASE_URL=file:./prisma/dev-test.db npx prisma migrate deploy')
    const module: TestingModule = await Test.createTestingModule({
      imports: [
        ConfigModule.forRoot({
            envFilePath: '.env.test'
        }),
        TasksModule,
        UsersModule,
        AuthModule
      ],
    }).compile();

    app = module.createNestApplication();

    app.useGlobalPipes(new ValidationPipe({
        whitelist: true, 
    })) 


    prismaService = module.get<PrismaService>(PrismaService)

    await app.init();
  });

  it('/ (GET)', () => {});


  afterEach(async () => {
    await prismaService.user.deleteMany()
  });

  afterEach(async () => {
    await app.close();
  });

  describe('/users', () => {
    it('/users (POST)- createUser', () =>{
        const createUserDto = {
          
        name: 'rodrigo',
        email: 'rodrigo@email.com',
        password: '123456'
        }

        const response = await request(app.getHttpServer())
        .post('/users')
        .send(createUserDto)


    })




  })
});
