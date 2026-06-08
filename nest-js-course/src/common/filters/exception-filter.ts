import { ExceptionFilter, Catch, HttpException, ArgumentsHost } from "@nestjs/common";
import { Response, Request } from "express"; // ✅ importar do express;


@Catch(HttpException)
export class ApiExceptionFilter implements ExceptionFilter {
    catch(exception: HttpException, host: ArgumentsHost) {

        const ctx = host.switchToHttp();
        const response = ctx.getResponse<Response>();
        const request = ctx.getRequest<Request>();
        const status = exception.getStatus();
        const errorResponse = exception.getResponse();

        console.log("PASSANDO DENTRO DE FILTER .........")

        // ✅ isso estava faltando — sem isso a requisição trava para sempre
        response.status(status).json({
            statusCode: status,
            timestamp: new Date().toISOString(),
            path: request.url,
            error: errorResponse
        });
    }
}