///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit NPC;

// npc will carry too many object if allow keep obj,see give.c
int no_keep(object ob) {
        return(1);
}

void create()
{
        object ob;
        set_name("刘云财", ({ "fish seller","seller","liu"}) );
        set("gender", "男性" );
        set("age", 36);
        set("long","这是一个老实巴交的中年汉子，在这儿等着收购别人钓上来的鱼。\n");
        set("combat_exp", 20000);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set("chat_chance",2);
        set("chat_msg", ({
                "刘云财说道：钓到好鱼一定卖给我啊!!!\n",
                "刘云财得意的说：把这些鱼卖到外面就发了…\n",
        }));

        carry_object("/obj/cloth")->wear();
        setup();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        int exp;
                if( !ob || environment(ob) != environment() ) return;
                exp=ob->query("combat_exp");

                if(exp<20000) {
        message_vision("张云财一见$N走过来，眼睛笑成了一条缝, 说道：这位" + RANK_D->query_respect(ob)+"是来钓鱼的吧?\n"
"张云财说：在这儿钓到的鱼我全部高价收购！！！\n"
"张云财说：把鱼给我(give seller fish)我就会给你钱的。\n", ob);
                tell_object(ob,YEL"张云财在你耳边偷偷说道：告诉你一个秘密，在这儿钓鱼(fish)还可以增加经验和潜能哦！\n"NOR
                        YEL"张云财说：如果钓到鱼，用(hp)命令就可以看到你增加的经验和潜能了。\n"NOR);
                }
}

int accept_object(object who, object ob)
{
        object pay;
        if( ob->is_character() ) {
                        tell_object(who,CYN"刘云财说道：可别开这种玩笑！\n"NOR);
                return 0;
                        }
        if(ob->query("name")==HIY"金鲤鱼"NOR){
                message_vision("$N给刘云财一条"+ob->query("name")+"。\n"NOR,who);
                message_vision(CYN"刘云财两眼发光，对$N激动的说道：好鱼！好鱼！\n"NOR,who);
                pay = new("/obj/money/silver");
                pay->set_amount(10);
                pay->move(who);
                tell_object(who,CYN"刘云财对你说：这是你的鱼钱。\n"NOR
                                                        "刘云财给了你一些银子。\n", who);
                return 1;
        }
        if(ob->query("name")=="大鲤鱼"){
                message_vision("$N给刘云财一条"+ob->query("name")+"。\n"NOR,who);
                        message_vision(CYN"刘云财点了点头，对$N说道：不错，不错。\n"NOR,who);
                        pay = new("/obj/money/silver");
                        pay->set_amount(5);
                        pay->move(who);
                        tell_object(who,CYN"刘云财对你说：这是你的鱼钱。\n"NOR
                                                        "刘云财给了你一些银子。\n", who);
                        return 1;
        }
        if(ob->query("name")=="小鱼"){
                message_vision("$N给刘云财一条"+ob->query("name")+"。\n"NOR,who);
                                message_vision(CYN"刘云财皱了皱眉头，对$N说道：这么小的鱼也拿来给我？\n"NOR,who);
                                pay = new("/obj/money/silver");
                                pay->set_amount(1);
                                pay->move(who);
                                tell_object(who,CYN"刘云财对你说：这是你的鱼钱。\n"NOR
                                                        "刘云财给了你一些银子。\n", who);
                                return 1;
        }
        return 0;
}
