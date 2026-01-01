/* assert.h standard header */
#undef assert	/* remove existing definition */

#ifdef NDEBUG
	#define assert(test)	((void)0)
#else		/* NDEBUG not defined */
	void _Assert(char *);
	/* macros */
	#define _STR(x) _VAL(x)
	#define _VAL(x) #x

    // # 运算符在宏展开之前执行
    // 如果直接写 _STR(x) #x 则__LINE__宏根本不会展开
    // 因此需要两层宏来保证宏展开

	#define assert(test)	((test) ? (void)0 \
		: _Assert(__FILE__ ":" _STR(__LINE__) " " #test))
#endif
