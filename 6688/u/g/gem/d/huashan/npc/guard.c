// guard.c -封不平
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("守门弟子",({"huashan dizi","dizi","guard"}));
        set("title", GRN "华山" NOR + YEL "剑宗" NOR + CYN "弟子" NOR);
        set("long",
                "这是一名华山剑宗的守门的弟子。正在看守本门的门户。\n");
        set("gender", "男性");
        set("age", 24);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 26);
        set("con", 26);
        set("dex", 26);
        set("combat_exp",100000);  

        set_skill("force", 50);
        set_skill("huashan-neigong", 50);
        set_skill("dodge", 50);
        set_skill("huashan-shenfa", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("huashan-jianfa", 50);
        set_skill("strike", 50);
        set_skill("hunyuan-zhang", 50);

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
