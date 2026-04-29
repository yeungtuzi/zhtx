#include "skillslv.h"

inherit "quest/killer/killer.c";

void set_skills()
{
        ::set_skills();
        set_skill("force", LV);             // 基本内功
        set_skill("huntian-qigong", LV);    // 混天气功
        set_skill("strike", LV);
        set_skill("xianglong-zhang", LV);   // 降龙十八掌
        set_skill("dodge", LV);             // 基本躲闪
        set_skill("xiaoyaoyou", LV);        // 逍遥游
        set_skill("parry", LV);             // 基本招架
        set_skill("staff", LV);             // 基本棍杖
        set_skill("dagou-bang", LV);        // 打狗棒法
        set_skill("begging", LV);           // 叫化绝活
        set_skill("checking", LV);          // 道听途说

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");

        prepare_skill("strike", "xianglong-zhang");
        set("skill_mark/dagou-bang",1);

        carry_object("/class/gaibang/yuzhu_zhang")->wield();
}


void heart_beat() {
   if (!query_temp("chan") && is_fighting())
      command("perform chan");
      ::heart_beat();
}


