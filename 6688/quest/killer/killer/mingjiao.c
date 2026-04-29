#include "skillslv.h"

inherit "quest/killer/killer.c";

void set_skills()
{
        ::set_skills();
        set_skill("force", LV);
        set_skill("parry", LV);
        set_skill("hand",LV);
        set_skill("cuff",LV);
        set_skill("iron-cloth",LV);
        set_skill("sword",LV);

        set_skill("jiuyang-shengong", LV);
        set_skill("qiankun-danuoyi", LV);
        set_skill("shenghuo-shengong",LV);
        set_skill("qishang-quan",LV);

        map_skill("force", "jiuyang-shengong");
        map_skill("iron-cloth", "jiuyang-shengong");
        map_skill("sword", "shenghuo-shengong");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("hand", "shenghuo-shengong");

        prepare_skill("cuff", "qishang-quan");
        create_family("明教", 8, "弟子");

        carry_object("/class/mingjiao/obj/skysword")->wield();
        carry_object("/class/mingjiao/obj/goldpao")->wear();

}


void heart_beat() {
   if (!query_temp("jiuyang-shield") && is_fighting())
      command("exert jiuyang-shield");
      ::heart_beat();
}


