package com.yin.mvnproject.demo01;

import static org.junit.Assert.assertEquals;
import org.junit.Test;

import com.yin.mvnproject.demo01.Util;

public class HelloWorldTest
{
    @Test
    public void testSayHello()
    {
        Util util = new Util();

        String result = util.sayHello();

        assertEquals( "Hello World", result );
    }
}
