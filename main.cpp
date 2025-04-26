#include "crow.h"
#include "Config/Auth.h"
#include "Helpers/Fs/Reader.h"
#include "Routes/Web.h"
#include "Routes/Api.h"
#include "Helpers/Fs/Dotenv.h"
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>
#include "Models/person.hxx"
#include "person-odb.hxx"

void loadConfig() {
    dotenv::init("../../.env");

    password = dotenv::getenv("PASSWORD");
    public_key = loadKey(dotenv::getenv("PUBLIC_KEY"));
    private_key = loadKey(dotenv::getenv("PRIVATE_KEY"));
}

std::shared_ptr<odb::mysql::database> setupDatabase() {
    std::string db_user = dotenv::getenv("MYSQL_USER");
    std::string db_pass = dotenv::getenv("MYSQL_PASS");
    std::string db_name = dotenv::getenv("MYSQL_DB");
    std::string db_host = dotenv::getenv("MYSQL_HOST");
    unsigned int db_port = std::stoi(dotenv::getenv("MYSQL_PORT"));

    return std::make_shared<odb::mysql::database>(db_user, db_pass, db_name, db_host, db_port);
}

void insertSampleData(const std::shared_ptr<odb::mysql::database>& db) {
    try {
        odb::transaction t(db->begin());

        Person p("Ali", 25);
        db->persist(p);

        t.commit();
    } catch (const std::exception& e) {
        std::cerr << "Database error: " << e.what() << std::endl;
    }
}

int main() {
    loadConfig();

    auto db = setupDatabase();
    insertSampleData(db);

    crow::SimpleApp app;
    set_global_base(dotenv::getenv("TEMPLATES"));

    addWebRoute(app);
    addApiRoute(app);

    app.port(18080).multithreaded().run();

    return 0;
}
