import { ExceptionFilter, Catch, HttpException, ArgumentsHost } from "@nestjs/common";

@Catch(HttpException)
export class ApiExpeptionFilter implements ExceptionFilter{
    catch(exception: HttpException, host: ArgumentsHost){

        const ctx = host.switchToHttp();
        const response = ctx.getResponse<Response>();
        const request = ctx.getRequest<Request>();
        const status = exception.getStatus();
        const errorResponse = exception.getResponse();

        console.log("PASSANDO DENTRO DE FILTER .........")

   
    }


}