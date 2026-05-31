"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
exports.getPrismaClientClass = getPrismaClientClass;
const runtime = __importStar(require("@prisma/client/runtime/client"));
const config = {
    "previewFeatures": [],
    "clientVersion": "7.8.0",
    "engineVersion": "3c6e192761c0362d496ed980de936e2f3cebcd3a",
    "activeProvider": "sqlite",
    "inlineSchema": "// This is your Prisma schema file,\n// learn more about it in the docs: https://pris.ly/d/prisma-schema\n\n// Get a free hosted Postgres database in seconds: `npx create-db`\n\ngenerator client {\n  provider     = \"prisma-client\"\n  output       = \"../src/generated/prisma\"\n  moduleFormat = \"cjs\"\n}\n\ndatasource db {\n  provider = \"sqlite\"\n}\n\nmodel Task {\n  id          Int     @id @default(autoincrement())\n  name        String\n  description String\n  completed   Boolean\n\n  createdAt DateTime? @default(now())\n}\n",
    "runtimeDataModel": {
        "models": {},
        "enums": {},
        "types": {}
    },
    "parameterizationSchema": {
        "strings": [],
        "graph": ""
    }
};
config.runtimeDataModel = JSON.parse("{\"models\":{\"Task\":{\"fields\":[{\"name\":\"id\",\"kind\":\"scalar\",\"type\":\"Int\"},{\"name\":\"name\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"description\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"completed\",\"kind\":\"scalar\",\"type\":\"Boolean\"},{\"name\":\"createdAt\",\"kind\":\"scalar\",\"type\":\"DateTime\"}],\"dbName\":null}},\"enums\":{},\"types\":{}}");
config.parameterizationSchema = {
    strings: JSON.parse("[\"where\",\"Task.findUnique\",\"Task.findUniqueOrThrow\",\"orderBy\",\"cursor\",\"Task.findFirst\",\"Task.findFirstOrThrow\",\"Task.findMany\",\"data\",\"Task.createOne\",\"Task.createMany\",\"Task.createManyAndReturn\",\"Task.updateOne\",\"Task.updateMany\",\"Task.updateManyAndReturn\",\"create\",\"update\",\"Task.upsertOne\",\"Task.deleteOne\",\"Task.deleteMany\",\"having\",\"_count\",\"_avg\",\"_sum\",\"_min\",\"_max\",\"Task.groupBy\",\"Task.aggregate\",\"AND\",\"OR\",\"NOT\",\"id\",\"name\",\"description\",\"completed\",\"createdAt\",\"equals\",\"in\",\"notIn\",\"lt\",\"lte\",\"gt\",\"gte\",\"not\",\"contains\",\"startsWith\",\"endsWith\",\"set\",\"increment\",\"decrement\",\"multiply\",\"divide\"]"),
    graph: "NwsQCBwAACkAMB0AAAQAEB4AACkAMB8CAAAAASABACsAISEBACsAISIgACwAISNAAC0AIQEAAAABACABAAAAAQAgCBwAACkAMB0AAAQAEB4AACkAMB8CACoAISABACsAISEBACsAISIgACwAISNAAC0AIQEjAAAuACADAAAABAAgAwAABQAwBAAAAQAgAwAAAAQAIAMAAAUAMAQAAAEAIAMAAAAEACADAAAFADAEAAABACAFHwIAAAABIAEAAAABIQEAAAABIiAAAAABI0AAAAABAQgAAAkAIAUfAgAAAAEgAQAAAAEhAQAAAAEiIAAAAAEjQAAAAAEBCAAACwAwAQgAAAsAMAUfAgA3ACEgAQA0ACEhAQA0ACEiIAA1ACEjQAA2ACECAAAAAQAgCAAADgAgBR8CADcAISABADQAISEBADQAISIgADUAISNAADYAIQIAAAAEACAIAAAQACACAAAABAAgCAAAEAAgAwAAAAEAIA8AAAkAIBAAAA4AIAEAAAABACABAAAABAAgBhUAAC8AIBYAADAAIBcAADMAIBgAADIAIBkAADEAICMAAC4AIAgcAAAaADAdAAAXABAeAAAaADAfAgAbACEgAQAcACEhAQAcACEiIAAdACEjQAAeACEDAAAABAAgAwAAFgAwFAAAFwAgAwAAAAQAIAMAAAUAMAQAAAEAIAgcAAAaADAdAAAXABAeAAAaADAfAgAbACEgAQAcACEhAQAcACEiIAAdACEjQAAeACENFQAAIwAgFgAAKAAgFwAAIwAgGAAAIwAgGQAAIwAgJAIAAAABJQIAAAAEJgIAAAAEJwIAAAABKAIAAAABKQIAAAABKgIAAAABKwIAJwAhDhUAACMAIBgAACYAIBkAACYAICQBAAAAASUBAAAABCYBAAAABCcBAAAAASgBAAAAASkBAAAAASoBAAAAASsBACUAISwBAAAAAS0BAAAAAS4BAAAAAQUVAAAjACAYAAAkACAZAAAkACAkIAAAAAErIAAiACELFQAAIAAgGAAAIQAgGQAAIQAgJEAAAAABJUAAAAAFJkAAAAAFJ0AAAAABKEAAAAABKUAAAAABKkAAAAABK0AAHwAhCxUAACAAIBgAACEAIBkAACEAICRAAAAAASVAAAAABSZAAAAABSdAAAAAAShAAAAAASlAAAAAASpAAAAAAStAAB8AIQgkAgAAAAElAgAAAAUmAgAAAAUnAgAAAAEoAgAAAAEpAgAAAAEqAgAAAAErAgAgACEIJEAAAAABJUAAAAAFJkAAAAAFJ0AAAAABKEAAAAABKUAAAAABKkAAAAABK0AAIQAhBRUAACMAIBgAACQAIBkAACQAICQgAAAAASsgACIAIQgkAgAAAAElAgAAAAQmAgAAAAQnAgAAAAEoAgAAAAEpAgAAAAEqAgAAAAErAgAjACECJCAAAAABKyAAJAAhDhUAACMAIBgAACYAIBkAACYAICQBAAAAASUBAAAABCYBAAAABCcBAAAAASgBAAAAASkBAAAAASoBAAAAASsBACUAISwBAAAAAS0BAAAAAS4BAAAAAQskAQAAAAElAQAAAAQmAQAAAAQnAQAAAAEoAQAAAAEpAQAAAAEqAQAAAAErAQAmACEsAQAAAAEtAQAAAAEuAQAAAAENFQAAIwAgFgAAKAAgFwAAIwAgGAAAIwAgGQAAIwAgJAIAAAABJQIAAAAEJgIAAAAEJwIAAAABKAIAAAABKQIAAAABKgIAAAABKwIAJwAhCCQIAAAAASUIAAAABCYIAAAABCcIAAAAASgIAAAAASkIAAAAASoIAAAAASsIACgAIQgcAAApADAdAAAEABAeAAApADAfAgAqACEgAQArACEhAQArACEiIAAsACEjQAAtACEIJAIAAAABJQIAAAAEJgIAAAAEJwIAAAABKAIAAAABKQIAAAABKgIAAAABKwIAIwAhCyQBAAAAASUBAAAABCYBAAAABCcBAAAAASgBAAAAASkBAAAAASoBAAAAASsBACYAISwBAAAAAS0BAAAAAS4BAAAAAQIkIAAAAAErIAAkACEIJEAAAAABJUAAAAAFJkAAAAAFJ0AAAAABKEAAAAABKUAAAAABKkAAAAABK0AAIQAhAAAAAAAAAS8BAAAAAQEvIAAAAAEBL0AAAAABBS8CAAAAATACAAAAATECAAAAATICAAAAATMCAAAAAQAAAAAFFQAGFgAHFwAIGAAJGQAKAAAAAAAFFQAGFgAHFwAIGAAJGQAKAQIBAgMBBQYBBgcBBwgBCQoBCgwCCw0DDA8BDRECDhIEERMBEhQBExUCGhgFGxkL"
};
async function decodeBase64AsWasm(wasmBase64) {
    const { Buffer } = await import('node:buffer');
    const wasmArray = Buffer.from(wasmBase64, 'base64');
    return new WebAssembly.Module(wasmArray);
}
config.compilerWasm = {
    getRuntime: async () => await import("@prisma/client/runtime/query_compiler_fast_bg.sqlite.js"),
    getQueryCompilerWasmModule: async () => {
        const { wasm } = await import("@prisma/client/runtime/query_compiler_fast_bg.sqlite.wasm-base64.js");
        return await decodeBase64AsWasm(wasm);
    },
    importName: "./query_compiler_fast_bg.js"
};
function getPrismaClientClass() {
    return runtime.getPrismaClient(config);
}
//# sourceMappingURL=class.js.map