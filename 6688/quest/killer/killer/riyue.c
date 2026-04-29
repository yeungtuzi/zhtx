#include "skillslv.h"

inherit "quest/killer/killer.c";

void set_skills()
{
        ::set_skills();
        create_family("日月神教", 8, "弟子");

        set_skill("force", LV);
        set_skill("kuihua-shengong", LV);
        set_skill("dodge", LV);
        set_skill("mo-zhang-jue", LV);
        set_skill("strike", LV);
        set_skill("mo-jian-jue", LV);
        set_skill("pixie-sword", LV);
        set_skill("parry", LV);
        set_skill("sword", LV);
        set_skill("literate", LV);
        set_skill("daguanming",LV);
        set_skill("perception",LV);

        map_skill("force", "kuihua-shengong");
        map_skill("strike", "mo-zhang-jue");
        map_skill("parry", "pixie-sword");
        map_skill("sword", "pixie-sword");
        map_skill("dodge", "kuihua-shengong");

        prepare_skill("strike", "mo-zhang-jue");

        carry_object("/class/heimuya/obj/dress")->wear();
        carry_object("/class/heimuya/obj/flower_boot")->wear();
        carry_object("/class/heimuya/obj/needle")->wield();

}


void heart_beat() {
   if (!query_temp("kuihua") && is_fighting())
      command("exert kuihua");
      ::heart_beat();
}


