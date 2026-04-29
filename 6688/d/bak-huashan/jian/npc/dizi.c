// fengbuping.c -封不平
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("华山弟子",({"huashan dizi","dizi"}));
        set("title", GRN "华山" NOR + YEL "剑宗" NOR + CYN "弟子" NOR);
        set("long",
                "这是一名华山剑宗的新入室的弟子。正在大师兄的指导下刻苦练习本门剑术。\n");
        set("gender", "男性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp",20000);  

        set_skill("force", 30);
        set_skill("huashan-neigong", 30);
        set_skill("dodge", 30);
        set_skill("huashan-shenfa", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_skill("huashan-jianfa", 30);
        set_skill("strike", 30);
        set_skill("hunyuan-zhang", 30);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        prepare_skill("strike", "hunyuan-zhang");
        create_family("华山派" , 19, "弟子");
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
