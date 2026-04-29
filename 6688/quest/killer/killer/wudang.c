#include "skillslv.h"

inherit "quest/killer/killer.c";

void set_skills()
{
        ::set_skills();
        set_skill("force", LV);
        set_skill("taiji-shengong", LV);
        set_skill("move", LV);
        set_skill("dodge", LV);
        set_skill("tiyunzong", LV);
        set_skill("cuff", LV);
        set_skill("taiji-quan", LV);
        set_skill("parry", LV);
        set_skill("sword", LV);
        set_skill("taiji-jian", LV);
        set_skill("taoism", LV);
        set_skill("literate", LV);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        carry_object("/d/wudang/obj/zhenwu")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}


void heart_beat() {
   if (!query_temp("pfm/wudang_chan") && is_fighting())
      command("perform chan");
      ::heart_beat();
}



