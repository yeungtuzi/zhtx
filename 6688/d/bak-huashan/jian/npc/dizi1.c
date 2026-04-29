// dizi1.c -剑宗的大弟子
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("李承志",({"li chengzhi","li","chengzhi"}));
        set("title", GRN "华山" NOR + YEL "剑宗" NOR + CYN "传人" NOR);
        set("long",
                "华山派剑宗传人。\n"
                "他是华山剑宗年轻一辈的第一高手。剑气之争剑宗一败涂地，封不平隐居苦练，。\n"
                "收下他这个徒弟，苦心栽培，现在他大有青出于蓝之势。\n");
        set("gender", "男性");
        set("age", 24);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("max_kee",  2000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 800000);
        set("score", 10000);
        set_skill("force", 100);
        set_skill("huashan-neigong", 100);
        set_skill("dodge", 120);
        set_skill("huashan-shenfa", 120);
        set_skill("parry", 120);
        set_skill("sword", 130);
        set_skill("huashan-jianfa", 120);
        set_skill("strike", 100);
        set_skill("hunyuan-zhang", 100);
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


