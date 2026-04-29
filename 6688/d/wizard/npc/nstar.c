#include <globals.h> 
#ifndef NPCDATA
#define NPCDATA "/data/user/n/"
#endif
#define WUDIE NPCDATA + "nstar"

inherit NPC;
inherit F_MASTER;
inherit F_SAVE;
 
string query_save_file()
{
        return WUDIE;
}
 
void create()
{
      seteuid(getuid());
      restore();
      set("id", "xi gua");
      set_name("冬瓜",({"dong gua","xi gua","n_star"}));
   carry_object("/obj/cloth.c")->wear();
   setup();
}

void init()
{
   command("smirk");
}
