// shangshan.c 赏善使者
//by masterall
 
 
#include <ansi.h>
 
inherit NPC;

string ask_zhou();
 
void consider();
 
void create()
{
        set_name("龙亦凡", ({ "long yifan", "long"}) );
        set("nickname", HIR"不败神龙" NOR);
        set("title", HIG"侠客岛"+HIY"岛主" NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
             "他就是传说中侠客岛的二位岛主之一。\n"
             "连名扬天下的赏善罚恶二使在他的面前都规规矩矩的，真不知他的功夫到了怎样的一个境界。\n"
        );
        set("attitude", "friendly");
        set("shen_type", 1);
        set("shen",3000000);
        set("str", 50);
        set("con", 50);
        set("int", 50);
        set("dex", 50);
        set("per", 30);
 
        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 250);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
 
        set("combat_exp", 100000000);
        set("score", 20000);

        set("inquiry", ([
                "腊八粥": (: ask_zhou :),
        ]));
         set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
                 (: consider :)
         }) );
 
         set_skill("force", 400);
         set_skill("dodge", 400);
         set_skill("mysterrier", 400);
         set_skill("xianglong-zhang",400);
         set_skill("strike",400);
         set_skill("parry", 400);
         set_skill("literate", 400);
         set_skill("jiuyang-shengong", 400);
         map_skill("force", "jiuyang-shengong");
         map_skill("parry", "xianglong-zhang");
         map_skill("strike", "xianglong-zhang");
         map_skill("dodge", "mysterrier");
         prepare_skill("strike", "xianglong-zhang");
         set_temp("jiuyang-shield", 1);

         setup();
         set_temp("apply/armor_vs_force",1000);
         set_temp("apply/armor",1000);
         carry_object("/d/xkd/obj/longcloth")->wear();
}

string ask_zhou()
{
     object me = this_player();
     object ob;

        if( !me->query("got_ling"))
        return "阁下好像并未收到赏善罚恶令，怎么跑到贵岛来了，难道真想有去无回吗？\n";

        if( me->query("got_zhou"))
        return "你已经要过一碗腊八粥了，怎么还这么贪吃，不怕吃出毛病来？！\n";

        command("say 阁下远道光临，敝岛无以为敬。这碗腊八粥外边倒还不易喝到， ");
        command("say 其中最主要的一味“断肠蚀骨腐心草”，要开花之后效力方著。但这草隔十年才开一次花。");
        command("say 我们总要等其开花之后，这才邀请江湖同道来此同享，屈指算来，这是第四回邀请。请，请，不用客气。");
        tell_object(me, HIG"龙岛主对身边仆从示意了一下，随即那人袍袖一拂，发出一股劲风，\n将一碗墨绿色的粥平平的向你送去，眼见就要整碗扣到你的身上，但那粥不再朝前飞出，\n略一停顿，随即向下飞落，稳稳地落入你的手中，但是这一手绝技，已经让你骇得说不出话来！！\n"NOR);      

                ob=new("/d/xkd/obj/zhou");
                ob->set("owner", me);
                ob->move(me);
                me->set("got_zhou",1);

}
 
