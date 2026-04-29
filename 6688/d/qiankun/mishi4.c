//ROOM:/d/qiankun/mishi4.c
//by masterall
//2003.6.30 

#include <ansi.h>
inherit "/u/l/lazypig/room/qiankuncave.c";

void create()
{
        set("short", HIC"乾坤教密室"NOR);
        set("long", @LONG
这是乾坤教的一间密室，四周通风良好，显然有气孔与外界相连，天花板
上有个天窗，透出微弱的光线。房间里光线极暗，隐隐的有青光闪动，似
乎密室的角落里还坐着一个人，你虽看不到他的存在，但是可以感觉到他
的杀气！
LONG
        );

        set("objects",([
                       __DIR__"npc/ke" : 1,
                      ])  );
           
 
        setup();

}

void init()
{ 
        add_action("do_jump","jump");
}
                                                        
int do_jump(string arg)
{
        object ob;
        if( arg=="天窗" )
         {
         if( arg == "天窗" && ob=present("ouyang ke", this_object()))
         {
              message_vision(HIB "欧阳克嘿嘿嘿奸笑起来：“此地乃本教机关重地，我受教主大恩来此看守，请阁下先过了小弟这一关！”\n" NOR,this_player());
              return 1;
         }
        
                if( this_player()->query("combat_exp")<5000000 )
                {
                        message_vision(HIR"$N纵身跳上天窗, 但高度不够, 从半空中又掉了下来，当时口吐白沫，昏了过去!\n"NOR,this_player());
                this_player()->unconcious();
                        return 1;
                }
                this_player()->receive_damage("kee",500);
message_vision(HIY"$N纵身一跃，身子平地直起，破窗而出，脸上却被窗框划了好几道口子！\n"NOR,this_player()); 
                this_player()->move(__DIR__"mishi5");
                return 1;
        }
        tell_object(this_player(),"你要跳到哪？\n");
        return 1;
}

