# Designing Data-Intensive Applications

So I'll put here some notes that I took while reading designing data intensive applications.

RELIABILITY:
 the system should continue to work correctly. Does what is expected even when things go wrong, prevent faults, AWS ritual machines sometimes crash without warning because they prioritize flexibility over a single machine reliability.

FAULT TOLERANCE: is a system’s ability to continue operating correctly even when some of its components fail.

Three types of faults hardware faults softer errors human errors.

 Response time for the client sees 

Legacy is the duration that I request is waiting to be handled.response time varies a lot.

TCP transmission control protocol.

HTTP message is handed down to TCP.

95th percentile response Time is 1.5 Seconds:  95 out of 100 requests take 1.5 seconds or more.

Amazon Latency is the duration that a request is waiting to be handled.

response time varies a lot.

TCP transmission control protocol.HTTP message is handed down to TCP.

When Amazon increases 100 hundred milliseconds in response time it reduces sales by one percent.

when several back and calls are needed to serve a request, it takes just a single slow back-end request to slow the entire nd process

Maintainability people dislike the maintenance of legacy systems. Operabiliity, simplicity and evolvability

Abstraction is a good way of removing accidental complexity.

Agile working patterns: test driven deployment TDD, refractoring. 

NoSQL emerged in the 2010’s. It was a try to beat the SQL predominance.Reinterpreted as “ not only sql” .

Independence mismatch: most code is written in OO languages. There has to be an awkward translation layer to relation of tables, that's why ORM's exist.

 noSQL is not well fit for many-to-many relationships.

THE NETWORK MODEL: links between models were not foreign keys, but more like pointers. It was difficult to make changes to these models

Conclusion: when it comes to representing one too many and many too many relationships ,relational and document databases are not fundamentally different. They use FK and document reference.

Document data models: schema flexibility, better performance due to locality, relational model better support for joins and many to one and many too many relationships.

When to use each: document model three of one too many relationship relationships not appealing for many to many relationship

SCHEMAS VS SCHEMALESS

Schemas are a good way of enforcing a structure

In situations of updating tables, schemaless documents can be more natural

CONVERSIONS BETWEEN RELATIONAL AND DOCUMENT DB’s

Relational DB’s support JSON documents (in the more recent years ) , on the document side rating DB supports relational like joints in its query languages.

A hybrid of both is a good rout for the future

DECLARATIVE VS IMPERATIVE LANGUAGES
 SQL was defined following the structure of the relation of algebra.

Declarative languages have a better chance of getting faster in parallel executions, because they only specify the pattern of the result, not the algorithm.

A great example of this is CSS and XSL ,they are both decorative, using the DOM API to change the color of a specific line of a HTML would be the equivalent of the imperative way of doing it

MAP REDUCING QUERY: programming model for processing large amount of data in book across many machines it's neither the clarity of nor of full imperative API somewhere in between

AGREGATTION PIPELINE: Is similar to SQL but uses a JSON-based format

GRAPH-LIKE DATA MODELS:

Vertices and edges, there are many known algorithms to make operations in this graphs.graphs are good for evolvability.

PROPERTY GRAPH MODEL(Cypher)

TRIPLE-STORE MODEL(SPARQL)

Cypher is a declarative query language for property graphs. Yes we can query it in SQL but with some difficulty.

SEMANTIC WEB: is very linked to triple star it was an idea to create kind of like a database of everything, but it was overhyped and never happened.

RESUME:

 Hierarchical Model ( Big Tree) → RELATIONAL (made to solve many-to-many) →  DOCUMENT DB and GRAPH DB ( both “NOSQL”)

Different systems for different purposes

ENGINES THAT POWER YOUR DATABASES

INDEXES: acts as a sign and helps locate data you want. They speed of the read, but they slow down the right because index need to be updated. Every time data is written.

HASH INDEXES (for key-value data)

It's basically a in memory hash map 

BITCASK engine: It's well suited if the value for each key is updated frequently, but it's kind of hard to keep all the keys in memory.

SSTABLES (Sorted String Table)

The sequence of key value pairs is sorted by key. You no longer need to keep an index of all the keys in memory merging segments is simple and efficient.

LMS-TREES (Log Structured Merge-Tree)

Basically means keeping a cascade off SS tables that are merged in the background, based on the principle of merging in compacting sorted files. Food tax index is much more complex than key value ones but based on similar idea

B-TREES

The most widely used index structure. Standard index implementation for most relation of databases and many no relational too.Like SStables they keep a key value pairs sorted by key.but they differ in design philosophy, log structure indexes break database into variable size segments, 

BTrees break down into fixed-size blocks or pages

4 kB in size, correspond more closely to the underlying hardware, also known as three of pages ,three always has the depth O(log n)

WAL(Write-ahead-along): to make resilient to crashes, backup

B-TREES VS LSM-TREES

B-TREES: faster reads, slower writes ( must write every data at least twice, one to the WAL and to the tree-page)

LSM-TREES: faster writes, slower reads (response time can sometimes be hight, B-trees can be more predictable)

In the excess can so far map a single key to value, but what if we need to query multiple columns of a table?

MULTI COLLUMN INDEX: is called concatenated index general way of query several columns at once very used for a geographical location

FULL-TEXT-SEARCH ENGINES: allow to search for similar keys, different than what we have seen so far which is searching assuming you know the exact data.

Lucine is a popular one , other fuzzy search techniques going to the direction of machine learning

TRANSACTION PROCESSIGN: means allowing clients to make a low latancy reads and writes, opposed to BATCH PROCESSING JOBS, which only run periodically

OLTP ONLINE-TRANSACTION-PROCESSING SYSTEMS: is small number of records per query, fetched by key

OLAP ONLINE-ANALYTIC-PROCESSING SYSTEMS: aggregate over a large number of records used for data analysis.

STAR AND SNOWFLAKE SCHEMAS

STAR: fact, table in the mirror surrounded by its dimension tables

SNOWFLAKE: the dimensions are further broken down into sub dimensions

DATA CUBES: materialized data cube

BACKWARD COMPATIBILITY: new code can read data that was written by order code

FOWARD COMPATIBILITY: older code can read newer code, it’s a bit  trickier

FORMATS FOR ENCODIGN DATA:

IN MEMORY

Some self contain sequence of bites (JSON document) when you want to write data to a file or send it over the network

turns it into a byte sequence

There are many built-in libraries for coding encoding. Python has pickle. Versioning and Efficiency data is often an afterthought in these libraries.

Decoding can be dangerous. (Hackers)

STANDARDIZED ENCODINGS: JSON , XML AND CSV

JSON and XML use more space than compared to binary formats

THRIFT AND PROTOCOL BUFFERS:

Binary encoding libraries there are based on the same principle, 

code generator tool that takes a schema definition and produces classes that implement the schema in various programming languages. You can use this generated code to encode or decode records of the schema.

AVRO: Provides compact encoding

Protocol buffers, thrift and avro all use schemas to describe a binary encoding format.

MOST COMMON WATS DATA FLOWS BETWEEN PROCESSES

1. VIA DATABASES
2. VIA SERVICE CALLS
3. VIA ASYNCHRONOUS MESSAGE PASSING

A service can itself be a kind to another service (web observer acts as a client to a database )

service oriented architecture/micro service architecture.

approach to web services

REST (HTTP AND URL) X SOAP(XML based)

 Swagger: used to describe restful API’s and produce documentation

RPC: Remote Procedure Call: abstract network communication so that executing code on a remote serve looks and feels like calling a local function. more used inside orgs

HTTP(Resource-oriented) VS RPC(Action Oriented)

ex: POST/users/123/orders VS getUserOrders(uderid)

MESSAGE BROKERS: asynchronous message-passing system that uses a ,essage queue to store temporary messages, the sender doesn’t wait for a response or the message to be delivered

acts like a middleware beetween sender and consumer

DISTRIBUTION OF DATA

Why distribute a database across multiple machinnes? Scalability, Fault tolerence, high availability, latency

SHARE NOTHING ARCHITECTURE:

horizontal scalling, more machinnes, each machinne is a node

There are two ways that data is distributed across different nodes

REPLICATION X PARTITIONING

kinda self explanning

REPLICATION: Leader-based replication. Leader and follower dinamic, followers are read-only from the client’s point of view