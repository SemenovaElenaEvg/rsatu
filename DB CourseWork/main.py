from http.server import HTTPServer, CGIHTTPRequestHandler
import cgi
import psycopg2
#import postgresql.driver as pg_driver

server_address = ("localhost", 8000)
httpd = HTTPServer(server_address, CGIHTTPRequestHandler)
httpd.serve_forever()

db = psycopg2.connect(user='postgres', password='postgres', host='127.0.0.1', database='postgres', port=5432)


#def auth(login, password):


