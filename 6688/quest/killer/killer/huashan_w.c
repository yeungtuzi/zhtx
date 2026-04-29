#include "skillslv.h"

inherit "quest/killer/killer.c";

void set_skills()
{
        ::set_skills();
        set("faith",10000);
        create_family("华山派剑宗", 8, "弟子");
        set_skill("force", LV);
        set_skill("huashan-neigong", LV);
        set_skill("dodge", LV);
        set_skill("huashan-shenfa", LV);
        set_skill("parry", LV);
        set_skill("sword", LV);
        set_skill("huashan-jianfa", LV);
        set_skill("wind-sword", LV);
        set_skill("strike", LV);
        set_skill("hunyuan-zhang", LV);
        set_skill("perception",LV);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "wind-sword");
        map_skill("sword", "wind-sword");

        prepare_skill("strike", "hunyuan-zhang");

        set_temp("apply/armor_vs_force",100);
        set_temp("apply/armor",150);
        set_temp("apply/damage",30);
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();


}


void heart_beat() {
   if (!query_temp("skill_mark/wind-sword") && is_fighting())
      command("perform hasten");
      ::heart_beat();
}


