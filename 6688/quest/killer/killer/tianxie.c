#include "skillslv.h"

inherit "quest/killer/killer.c";

void set_skills()
{
        ::set_skills();
         set("bellicosity",2000000);
        create_family("天邪派", 8, "弟子");
        set_skill("force", LV);
        set_skill("strike", LV);
        set_skill("sword", LV);
        set_skill("blade", LV);
        set_skill("parry", LV);
        set_skill("dodge", LV);
        set_skill("throwing", LV);

        set_skill("celestial", LV);
        set_skill("celestrike", LV);
        set_skill("spring-blade", LV);
        set_skill("pyrobat-steps", LV);
        set_skill("perception",LV);

        map_skill("force", "celestial");
        map_skill("strike","celestrike");
        prepare_skill("strike", "celestrike");
        map_skill("blade", "spring-blade");
        map_skill("dodge", "pyrobat-steps");

        set("skill_mark/spring-blade",1);

        carry_object("/class/fighter/houndbane")->wield();
        carry_object("/obj/cloth")->wear();
        //carry_object("/class/fighter/dragon_armor")->wear();



}


void heart_beat() {
   if (!query_temp("powerup") && is_fighting())
      command("exert powerup");
      ::heart_beat();
}


