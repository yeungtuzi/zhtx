#include <globals.h> 
#ifndef NPCDATA
#define NPCDATA "/data/user/j/"
#endif
#define WUDIE NPCDATA + "jean"

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
      set("id", "jean");
      set_name("舞蝶",({"jean","wudie","oracle"}));
   carry_object("/obj/cloth/ducloth.c")->wear();
   setup();
}

void init()
{
   command("fu");
    command("face");
}
