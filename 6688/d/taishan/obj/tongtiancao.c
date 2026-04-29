// medicine: tongtiancao.c
// Jay 3/18/96

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("通天草", ({"tongtian cao", "cao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支只有在绝顶泰山上才能生长的通天草。\n");
                set("value", 10);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
             this_player()->add("food", 20);

// function of this medicine needed here

message_vision("$N吃下一棵通天草，只觉得一阵清凉 !\n", this_player());

       destruct(this_object());
       return 1;
}

