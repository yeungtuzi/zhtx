inherit ROOM;

void create ()
{
        set ("short", "菜鸟之家");
        set ("long", 
@LONG
这里就是传说中的菜鸟————一点红的窝。
LONG);
        
        set("valid_startroom", 1);
        replace_program(ROOM);
        setup();
}



