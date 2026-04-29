#include "skillslv.h"

inherit "quest/killer/killer.c";

void set_skills()
{
        ::set_skills();
        set_skill("huashan-neigong", LV);
        set_skill("dodge", LV);
        set_skill("huashan-shenfa", LV);
        set_skill("parry", LV);
        set_skill("sword", LV);
        set_skill("dugu-jiujian",LV);
        set_skill("literate", LV);
        set_skill("cuff", LV);
        set_skill("strike", LV);
        set_skill("perception", LV);
        set_skill("dagger", LV);
        set_skill("spear", LV);
        set_skill("blade", LV);
        set_skill("throwing", LV);
        set_skill("whip", LV);
        set_skill("zong-jue",LV);
        set_skill("perception",LV);
        map_skill("literate","zong-jue");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");

        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();

}


void heart_beat() {
   if (!query_temp("prepare_dugu") && is_fighting())
      command("perform po-jian");
      ::heart_beat();
}


