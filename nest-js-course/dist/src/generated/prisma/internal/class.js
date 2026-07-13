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
    "inlineSchema": "// This is your Prisma schema file,\n// learn more about it in the docs: https://pris.ly/d/prisma-schema\n\n// Get a free hosted Postgres database in seconds: `npx create-db`\n\ngenerator client {\n  provider     = \"prisma-client\"\n  output       = \"../src/generated/prisma\"\n  moduleFormat = \"cjs\"\n}\n\ndatasource db {\n  provider = \"sqlite\"\n}\n\nmodel Task {\n  id          Int     @id @default(autoincrement())\n  name        String\n  description String\n  completed   Boolean\n\n  createdAt DateTime? @default(now())\n  userId    Int?\n  user      User?     @relation(fields: [userId], references: [id], onDelete: Cascade)\n}\n\nmodel User {\n  id           Int     @id @default(autoincrement())\n  name         String\n  passwordHash String\n  email        String  @unique\n  active       Boolean @default(true)\n  avatar       String?\n\n  createdAt DateTime? @default(now())\n  Task      Task[] // um user pode ter varias tasks\n}\n",
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
config.runtimeDataModel = JSON.parse("{\"models\":{\"Task\":{\"fields\":[{\"name\":\"id\",\"kind\":\"scalar\",\"type\":\"Int\"},{\"name\":\"name\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"description\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"completed\",\"kind\":\"scalar\",\"type\":\"Boolean\"},{\"name\":\"createdAt\",\"kind\":\"scalar\",\"type\":\"DateTime\"},{\"name\":\"userId\",\"kind\":\"scalar\",\"type\":\"Int\"},{\"name\":\"user\",\"kind\":\"object\",\"type\":\"User\",\"relationName\":\"TaskToUser\"}],\"dbName\":null},\"User\":{\"fields\":[{\"name\":\"id\",\"kind\":\"scalar\",\"type\":\"Int\"},{\"name\":\"name\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"passwordHash\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"email\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"active\",\"kind\":\"scalar\",\"type\":\"Boolean\"},{\"name\":\"avatar\",\"kind\":\"scalar\",\"type\":\"String\"},{\"name\":\"createdAt\",\"kind\":\"scalar\",\"type\":\"DateTime\"},{\"name\":\"Task\",\"kind\":\"object\",\"type\":\"Task\",\"relationName\":\"TaskToUser\"}],\"dbName\":null}},\"enums\":{},\"types\":{}}");
config.parameterizationSchema = {
    strings: JSON.parse("[\"where\",\"orderBy\",\"cursor\",\"Task\",\"_count\",\"user\",\"Task.findUnique\",\"Task.findUniqueOrThrow\",\"Task.findFirst\",\"Task.findFirstOrThrow\",\"Task.findMany\",\"data\",\"Task.createOne\",\"Task.createMany\",\"Task.createManyAndReturn\",\"Task.updateOne\",\"Task.updateMany\",\"Task.updateManyAndReturn\",\"create\",\"update\",\"Task.upsertOne\",\"Task.deleteOne\",\"Task.deleteMany\",\"having\",\"_avg\",\"_sum\",\"_min\",\"_max\",\"Task.groupBy\",\"Task.aggregate\",\"User.findUnique\",\"User.findUniqueOrThrow\",\"User.findFirst\",\"User.findFirstOrThrow\",\"User.findMany\",\"User.createOne\",\"User.createMany\",\"User.createManyAndReturn\",\"User.updateOne\",\"User.updateMany\",\"User.updateManyAndReturn\",\"User.upsertOne\",\"User.deleteOne\",\"User.deleteMany\",\"User.groupBy\",\"User.aggregate\",\"AND\",\"OR\",\"NOT\",\"id\",\"name\",\"passwordHash\",\"email\",\"active\",\"avatar\",\"createdAt\",\"equals\",\"in\",\"notIn\",\"lt\",\"lte\",\"gt\",\"gte\",\"not\",\"contains\",\"startsWith\",\"endsWith\",\"every\",\"some\",\"none\",\"description\",\"completed\",\"userId\",\"is\",\"isNot\",\"connectOrCreate\",\"upsert\",\"createMany\",\"set\",\"disconnect\",\"delete\",\"connect\",\"updateMany\",\"deleteMany\",\"increment\",\"decrement\",\"multiply\",\"divide\"]"),
    graph: "gAEWIAoFAABXACAuAABUADAvAAAFABAwAABUADAxAgAAAAEyAQBLACE3QABOACFGAQBLACFHIABMACFIAgBWACEBAAAAAQAgCwMAAE8AIC4AAEoAMC8AAAMAEDAAAEoAMDECAFUAITIBAEsAITMBAEsAITQBAEsAITUgAEwAITYBAE0AITdAAE4AIQEAAAADACAKBQAAVwAgLgAAVAAwLwAABQAQMAAAVAAwMQIAVQAhMgEASwAhN0AATgAhRgEASwAhRyAATAAhSAIAVgAhAwUAAHoAIDcAAFgAIEgAAFgAIAMAAAAFACABAAAGADACAAABACABAAAABQAgAQAAAAEAIAMAAAAFACABAAAGADACAAABACADAAAABQAgAQAABgAwAgAAAQAgAwAAAAUAIAEAAAYAMAIAAAEAIAcFAAB5ACAxAgAAAAEyAQAAAAE3QAAAAAFGAQAAAAFHIAAAAAFIAgAAAAEBCwAADQAgBjECAAAAATIBAAAAATdAAAAAAUYBAAAAAUcgAAAAAUgCAAAAAQELAAAPADABCwAADwAwAQAAAAMAIAcFAAB4ACAxAgBiACEyAQBeACE3QABhACFGAQBeACFHIABfACFIAgB3ACECAAAAAQAgCwAAEwAgBjECAGIAITIBAF4AITdAAGEAIUYBAF4AIUcgAF8AIUgCAHcAIQIAAAAFACALAAAVACACAAAABQAgCwAAFQAgAQAAAAMAIAMAAAABACASAAANACATAAATACABAAAAAQAgAQAAAAUAIAcEAAByACAYAABzACAZAAB2ACAaAAB1ACAbAAB0ACA3AABYACBIAABYACAJLgAAUAAwLwAAHQAQMAAAUAAwMQIAOQAhMgEAOgAhN0AAPQAhRgEAOgAhRyAAOwAhSAIAUQAhAwAAAAUAIAEAABwAMBcAAB0AIAMAAAAFACABAAAGADACAAABACALAwAATwAgLgAASgAwLwAAAwAQMAAASgAwMQIAAAABMgEASwAhMwEASwAhNAEAAAABNSAATAAhNgEATQAhN0AATgAhAQAAACAAIAEAAAAgACADAwAAcQAgNgAAWAAgNwAAWAAgAwAAAAMAIAEAACMAMAIAACAAIAMAAAADACABAAAjADACAAAgACADAAAAAwAgAQAAIwAwAgAAIAAgCAMAAHAAIDECAAAAATIBAAAAATMBAAAAATQBAAAAATUgAAAAATYBAAAAATdAAAAAAQELAAAnACAHMQIAAAABMgEAAAABMwEAAAABNAEAAAABNSAAAAABNgEAAAABN0AAAAABAQsAACkAMAELAAApADAIAwAAYwAgMQIAYgAhMgEAXgAhMwEAXgAhNAEAXgAhNSAAXwAhNgEAYAAhN0AAYQAhAgAAACAAIAsAACwAIAcxAgBiACEyAQBeACEzAQBeACE0AQBeACE1IABfACE2AQBgACE3QABhACECAAAAAwAgCwAALgAgAgAAAAMAIAsAAC4AIAMAAAAgACASAAAnACATAAAsACABAAAAIAAgAQAAAAMAIAcEAABZACAYAABaACAZAABdACAaAABcACAbAABbACA2AABYACA3AABYACAKLgAAOAAwLwAANQAQMAAAOAAwMQIAOQAhMgEAOgAhMwEAOgAhNAEAOgAhNSAAOwAhNgEAPAAhN0AAPQAhAwAAAAMAIAEAADQAMBcAADUAIAMAAAADACABAAAjADACAAAgACAKLgAAOAAwLwAANQAQMAAAOAAwMQIAOQAhMgEAOgAhMwEAOgAhNAEAOgAhNSAAOwAhNgEAPAAhN0AAPQAhDQQAAEQAIBgAAEkAIBkAAEQAIBoAAEQAIBsAAEQAIDgCAAAAATkCAAAABDoCAAAABDsCAAAAATwCAAAAAT0CAAAAAT4CAAAAAT8CAEgAIQ4EAABEACAaAABHACAbAABHACA4AQAAAAE5AQAAAAQ6AQAAAAQ7AQAAAAE8AQAAAAE9AQAAAAE-AQAAAAE_AQBGACFAAQAAAAFBAQAAAAFCAQAAAAEFBAAARAAgGgAARQAgGwAARQAgOCAAAAABPyAAQwAhDgQAAD8AIBoAAEIAIBsAAEIAIDgBAAAAATkBAAAABToBAAAABTsBAAAAATwBAAAAAT0BAAAAAT4BAAAAAT8BAEEAIUABAAAAAUEBAAAAAUIBAAAAAQsEAAA_ACAaAABAACAbAABAACA4QAAAAAE5QAAAAAU6QAAAAAU7QAAAAAE8QAAAAAE9QAAAAAE-QAAAAAE_QAA-ACELBAAAPwAgGgAAQAAgGwAAQAAgOEAAAAABOUAAAAAFOkAAAAAFO0AAAAABPEAAAAABPUAAAAABPkAAAAABP0AAPgAhCDgCAAAAATkCAAAABToCAAAABTsCAAAAATwCAAAAAT0CAAAAAT4CAAAAAT8CAD8AIQg4QAAAAAE5QAAAAAU6QAAAAAU7QAAAAAE8QAAAAAE9QAAAAAE-QAAAAAE_QABAACEOBAAAPwAgGgAAQgAgGwAAQgAgOAEAAAABOQEAAAAFOgEAAAAFOwEAAAABPAEAAAABPQEAAAABPgEAAAABPwEAQQAhQAEAAAABQQEAAAABQgEAAAABCzgBAAAAATkBAAAABToBAAAABTsBAAAAATwBAAAAAT0BAAAAAT4BAAAAAT8BAEIAIUABAAAAAUEBAAAAAUIBAAAAAQUEAABEACAaAABFACAbAABFACA4IAAAAAE_IABDACEIOAIAAAABOQIAAAAEOgIAAAAEOwIAAAABPAIAAAABPQIAAAABPgIAAAABPwIARAAhAjggAAAAAT8gAEUAIQ4EAABEACAaAABHACAbAABHACA4AQAAAAE5AQAAAAQ6AQAAAAQ7AQAAAAE8AQAAAAE9AQAAAAE-AQAAAAE_AQBGACFAAQAAAAFBAQAAAAFCAQAAAAELOAEAAAABOQEAAAAEOgEAAAAEOwEAAAABPAEAAAABPQEAAAABPgEAAAABPwEARwAhQAEAAAABQQEAAAABQgEAAAABDQQAAEQAIBgAAEkAIBkAAEQAIBoAAEQAIBsAAEQAIDgCAAAAATkCAAAABDoCAAAABDsCAAAAATwCAAAAAT0CAAAAAT4CAAAAAT8CAEgAIQg4CAAAAAE5CAAAAAQ6CAAAAAQ7CAAAAAE8CAAAAAE9CAAAAAE-CAAAAAE_CABJACELAwAATwAgLgAASgAwLwAAAwAQMAAASgAwMQIAVQAhMgEASwAhMwEASwAhNAEASwAhNSAATAAhNgEATQAhN0AATgAhCzgBAAAAATkBAAAABDoBAAAABDsBAAAAATwBAAAAAT0BAAAAAT4BAAAAAT8BAEcAIUABAAAAAUEBAAAAAUIBAAAAAQI4IAAAAAE_IABFACELOAEAAAABOQEAAAAFOgEAAAAFOwEAAAABPAEAAAABPQEAAAABPgEAAAABPwEAQgAhQAEAAAABQQEAAAABQgEAAAABCDhAAAAAATlAAAAABTpAAAAABTtAAAAAATxAAAAAAT1AAAAAAT5AAAAAAT9AAEAAIQNDAAAFACBEAAAFACBFAAAFACAJLgAAUAAwLwAAHQAQMAAAUAAwMQIAOQAhMgEAOgAhN0AAPQAhRgEAOgAhRyAAOwAhSAIAUQAhDQQAAD8AIBgAAFMAIBkAAD8AIBoAAD8AIBsAAD8AIDgCAAAAATkCAAAABToCAAAABTsCAAAAATwCAAAAAT0CAAAAAT4CAAAAAT8CAFIAIQ0EAAA_ACAYAABTACAZAAA_ACAaAAA_ACAbAAA_ACA4AgAAAAE5AgAAAAU6AgAAAAU7AgAAAAE8AgAAAAE9AgAAAAE-AgAAAAE_AgBSACEIOAgAAAABOQgAAAAFOggAAAAFOwgAAAABPAgAAAABPQgAAAABPggAAAABPwgAUwAhCgUAAFcAIC4AAFQAMC8AAAUAEDAAAFQAMDECAFUAITIBAEsAITdAAE4AIUYBAEsAIUcgAEwAIUgCAFYAIQg4AgAAAAE5AgAAAAQ6AgAAAAQ7AgAAAAE8AgAAAAE9AgAAAAE-AgAAAAE_AgBEACEIOAIAAAABOQIAAAAFOgIAAAAFOwIAAAABPAIAAAABPQIAAAABPgIAAAABPwIAPwAhDQMAAE8AIC4AAEoAMC8AAAMAEDAAAEoAMDECAFUAITIBAEsAITMBAEsAITQBAEsAITUgAEwAITYBAE0AITdAAE4AIUkAAAMAIEoAAAMAIAAAAAAAAAFOAQAAAAEBTiAAAAABAU4BAAAAAQFOQAAAAAEFTgIAAAABVAIAAAABVQIAAAABVgIAAAABVwIAAAABCxIAAGQAMBMAAGkAMEsAAGUAMEwAAGYAME0AAGcAIE4AAGgAME8AAGgAMFAAAGgAMFEAAGgAMFIAAGoAMFMAAGsAMAUxAgAAAAEyAQAAAAE3QAAAAAFGAQAAAAFHIAAAAAECAAAAAQAgEgAAbwAgAwAAAAEAIBIAAG8AIBMAAG4AIAELAACAAQAwCgUAAFcAIC4AAFQAMC8AAAUAEDAAAFQAMDECAAAAATIBAEsAITdAAE4AIUYBAEsAIUcgAEwAIUgCAFYAIQIAAAABACALAABuACACAAAAbAAgCwAAbQAgCS4AAGsAMC8AAGwAEDAAAGsAMDECAFUAITIBAEsAITdAAE4AIUYBAEsAIUcgAEwAIUgCAFYAIQkuAABrADAvAABsABAwAABrADAxAgBVACEyAQBLACE3QABOACFGAQBLACFHIABMACFIAgBWACEFMQIAYgAhMgEAXgAhN0AAYQAhRgEAXgAhRyAAXwAhBTECAGIAITIBAF4AITdAAGEAIUYBAF4AIUcgAF8AIQUxAgAAAAEyAQAAAAE3QAAAAAFGAQAAAAFHIAAAAAEEEgAAZAAwSwAAZQAwTQAAZwAgUQAAaAAwAAAAAAAABU4CAAAAAVQCAAAAAVUCAAAAAVYCAAAAAVcCAAAAAQcSAAB7ACATAAB-ACBLAAB8ACBMAAB9ACBPAAADACBQAAADACBRAAAgACADEgAAewAgSwAAfAAgUQAAIAAgAwMAAHEAIDYAAFgAIDcAAFgAIAcxAgAAAAEyAQAAAAEzAQAAAAE0AQAAAAE1IAAAAAE2AQAAAAE3QAAAAAECAAAAIAAgEgAAewAgAwAAAAMAIBIAAHsAIBMAAH8AIAkAAAADACALAAB_ACAxAgBiACEyAQBeACEzAQBeACE0AQBeACE1IABfACE2AQBgACE3QABhACEHMQIAYgAhMgEAXgAhMwEAXgAhNAEAXgAhNSAAXwAhNgEAYAAhN0AAYQAhBTECAAAAATIBAAAAATdAAAAAAUYBAAAAAUcgAAAAAQEFBAICAwcBBAADAQMIAAABBRICAQUYAgUEAAgYAAkZAAoaAAsbAAwAAAAAAAUEAAgYAAkZAAoaAAsbAAwAAAUEABEYABIZABMaABQbABUAAAAAAAUEABEYABIZABMaABQbABUGAgEHCQEICgEJCwEKDAEMDgENEAQOEQUPFAEQFgQRFwYUGQEVGgEWGwQcHgcdHw0eIQIfIgIgJAIhJQIiJgIjKAIkKgQlKw4mLQInLwQoMA8pMQIqMgIrMwQsNhAtNxY"
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