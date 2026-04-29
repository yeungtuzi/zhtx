// 云中界 area
// 姬良
// 门派自动介绍
// by dongsw 2003

#include <ansi.h>
inherit NPC;
inherit __DIR__"intro.c";

void create()
{
        set_name("姬良", ({ "ji liang" ,"liang"}) );
        set("gender", "男性" );
        set("age", 22);
        set("per", 50);
        set("title", YEL"新人导师"NOR);
        set("long","一位白衫青年，仙风道骨，仪表不凡。\n");

        carry_object("/obj/cloth")->wear();
        setup();

}

int do_visit(object me)
{
        string arg, *menpai_name;
        int i;
        
        menpai_name = keys(intro);
        
        tell_object(me,"姬良：“现今的世界中门派众多，武功纷繁复杂，我可以提供给你各个门派的一些情况。”\n"
                       "姬良：“你想了解哪个门派的大体情况？”\n\n");
        
        arg = "纵横门派：（总共" + chinese_number(sizeof(menpai_name)) + "个）\n";
        
        for(i=0;i<sizeof(menpai_name);i++)
        {
                arg += menpai_name[i] + (((i != sizeof(menpai_name) /2) 
                       && (i != sizeof(menpai_name) -1)) ? "、" : "。\n");
        }
        
        arg += "\n姬良：“说吧，你想了解哪个门派的大体情况？”\n"
                 "请直接输入门派的中文名称：（例如：少林派，结束请输入 n）";
                 
        write(arg);
        
        input_to("ask_choice", menpai_name);
        return 1;
}

int ask_choice(string arg, string *menpai_name)
{
        object me = this_player(), obj = new(__DIR__"obj/9dan");
        string msg, *intr;
        
        if(member_array(arg, menpai_name) != -1)
        {
                msg = intro[arg];
                intr = explode(msg, "。");
                tell_object(me,"\n姬良：“好吧，你听好了，" + arg + "的大体情况是这样的。”\n");
                me->start_busy(10);
                call_out("say_intro", 5, me, intr, 0, arg);
        }
        else if( arg == "n" || arg == "N")
        {
                tell_object(me,"\n姬良：“飞行包是我的一个法器，或许可以对你有点用处，你可以在京城的中心找我要。”\n");
                tell_object(me,"姬良：“如果你对着飞行包诚心的祷告期盼飞翔，我想你会有所收获！好了，你可以走了。”\n\n");

                if( me->query("newbie_gift") != "got")
                {
                        tell_object(me,"姬良：“鉴于你在新手村的出色表现，现特赐你九转金丹一粒，可以助你提高自身的内力修为。”\n"
                                       "姬良交给你一粒九转金丹。\n\n");
                        obj->set("owner", me);
                        obj->move(me);
                }

                me->start_busy(10);
                call_out("move_yun", 5, me);
        }
        else
        {
                write("\n请直接输入门派的中文名称：（例如：少林派，结束请输入 n）");
                input_to("ask_choice", menpai_name);    
        }
        return 1;
}

int say_intro(object me, string *intr, int i, string arg)
{
        me->interrupt_me(me,"death");
        
        if (i != sizeof(intr))
        {
                write("\n姬良：“" + intr[i] + "。”\n");
                i++;
        }
        else
        {
                write("\n姬良：“" + arg + "的大体情况就是这样了，你还想了解其他门派的情况吗？(y/n)”\n");
                input_to("ask_another", arg, me);
                return 1;
        }
        
        me->start_busy(10);
        call_out("say_intro", 5, me, intr, i, arg);
}

int ask_another(string arg, string menpai, object me)
{
        object obj = new("/d/sky/npc/obj/9dan");
        
        if( arg == "y" || arg == "N")
        {
                do_visit(me);
                return 1;
        }
        else if( arg =="n" || arg == "N")
        {
                tell_object(me,"\n姬良：“飞行包是我的一个法器，或许可以对你有点用处，你可以在京城的中心找我要。”\n");
                tell_object(me,"姬良：“如果你对着飞行包诚心的祷告期盼飞翔，我想你会有所收获！”\n\n");
                
                if( me->query("newbie_gift") != "got")
                {
                        tell_object(me,"姬良：“鉴于你在新手村的出色表现，现特赐你九转金丹一粒，可以助你提高自身的内力修为。”\n"
                                       "姬良交给你一粒九转金丹。\n\n");
                        obj->set("owner", me);
                        obj->move(me);
                }
                
                me->start_busy(10);
                call_out("move_yun", 5, me);
                return 1;
        }
        else
        {
                write("姬良：“" + menpai + "的大体情况就是这样了，你还想了解其他门派的情况吗？(y/n)”\n\n");
                input_to("ask_another", menpai, me);
                return 1;
        }
}
                
int move_yun(object me)
{
        me->interrupt_me(me,"death");
        tell_object(me,HIB"\n你心中默默祷告：“飞行包，请带我飞翔吧！”\n");
        tell_object(me,HIB"只见飞行包发出淡淡的蓝光包裹着你钻入了云中。\n"NOR);         
        me->move("/d/sky/yun");
        me->start_busy(10);
        call_out("move_tian", 5, me);
        return 1;
}

int move_tian(object ob)
{
        ob->interrupt_me(ob,"death");
        tell_object(ob, "\n飞行包带你在云中转了几圈后终于来到了高空之上。\n\n");
        ob->move("/d/sky/tian");
        return 1;
}
